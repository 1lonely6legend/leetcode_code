//
// Created by ogier on 2023/5/10.
// https://www.zhihu.com/question/21923021/answer/769606119
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class KMP {
 public:
  /*
   * @brief 构造函数
   * @param stringa 主串
   * @param stringb 模式串
   * @return 无
   */
  KMP(string stringa, string stringb) : s1(stringa), s2(stringb) {}

  /*
   * @brief 计算前缀函数,还有更优算法,见https://oi-wiki.org/string/kmp/
   * @return 前缀函数数组
   */
  vector<int> prefix_function() {//前缀函数数组
    //还有一种
    /*int n = (int) s2.length();
    vector<int> pi(n);//初始化数组长度,并且全部为0
    for (int i = 1; i < n; i++)
      //从第二个数开始遍历
      for (int j = pi[i - 1] + 1; j >= 0; j--)  // improved: j=i => j=pi[i-1]+1
        //令j=pi[i-1]+1,相邻的前缀最多加一,所以只遍历pi[i-1]+1个,节省时间
        //然后从最长的前缀开始,依次判断是否相等
        if (s2.substr(0, j) == s2.substr(i - j + 1, j)) {
          //判断当前这一段0-i的字符串,前缀j个和后缀j个的字符是否一致
          pi[i] = j;
          break;
        }
    prefix = pi;
    return pi;*/
    int n = (int) s2.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s2[i] != s2[j])
        j = pi[j - 1];
      if (s2[i] == s2[j])
        j++;
      pi[i] = j;
    }
    prefix = pi;
    return pi;

  }

  /*
   * @brief KMP算法
   * @return 匹配的位置
   */
  int match_position() {
    //最好debug看一下,要不看不明白
    int n = (int) s1.length(), m = (int) s2.length();
    for (int i = 0, j = 0; i < n; i++) {
      //对主串每一位进行一个遍历
      while (j > 0 && s1[i] != s2[j]) {
        //如果在第二位之之后出现不匹配,使用prefix回溯
        j = prefix[j - 1];
      }
      if (s1[i] == s2[j]) {
        j++;
      }
      if (j == m) {
        //成功找到匹配的串
        return i - m + 1;
      }
    }
    return -1;
  }

 private:
  string s1;
  string s2;
  vector<int> prefix;
};

int main() {
  string stringa = {"abababf"};
  string stringb = {"ababf"};
  string tmp = stringa.substr(0, 0);
  //初始化
  KMP K = KMP(stringa, stringb);
//  vector<int> res = K.prefix_function();
//  for (auto num : res) {
//    std::cout << num << '\n';
//  }

  //计算前缀数组
  K.prefix_function();
  //匹配字符串位置
  std::cout << K.match_position();
  return 0;
}