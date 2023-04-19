//
// Created by ogier on 2023/4/18.
// 392. 判断子序列
// https://leetcode.cn/problems/is-subsequence/solution/pan-duan-zi-xu-lie-by-leetcode-solution/
#include <iostream>
#include <string>

using std::string;

bool isSubsequence(string s, string t) {
  //保存两个字符串的长度
  int size_s = s.size();
  int size_t = t.size();
  //保存第一个字符串的遍历位置
  int i = 0;
  //下面对字符串t进行遍历
  for (int j = 0; j < size_t; ++j) {
    //如果当前位置的s与t的字符相匹配
    if (s[i] == t[j]) {
      ++i;//那么就将对s的下一个字符进行匹配寻找,
      //此时t字符串不会从头开始寻找,接着之前的
    }
  }
  //这时候说明t字符串已经走完一遍了,如果此时s字符串没有到最后,说明s中有一个字符在t中没有找到
  if (i != size_s)//直接返回false
    return false;
  return true;
}

int main() {
  string s1 = {"a"};
  string s2 = {""};
  bool ans;
  ans = isSubsequence(s1, s2);
  std::cout << ans;
  return 0;
}
