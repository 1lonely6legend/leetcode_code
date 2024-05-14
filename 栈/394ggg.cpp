//
// Created by ogier on 24-5-13.
//
#include <stack>
#include <climits>
#include<string>
using namespace std;
class Solution {
  public:
    string decodeString(string s) {
      //存储数字的栈
      stack<int> times_st;
      //存储字符串的栈
      stack<string> str_st;
      //临时字符串
      string cur_str;
      int n = s.size();
      int nums = 0;

      for (int i = 0; i < n; i++) {
        char ch = s[i];
        //如果字符为数字
        if (isdigit(ch)) {
          nums = nums * 10 + ch - '0'; //更新nums的值
        }
        //如果字符为【
        else if (ch == '[') {
          times_st.push(nums); //nums入栈
          nums = 0; //nums重置为0
          str_st.push(cur_str); //将cur_str入栈
          cur_str = ""; //清空cur_str
        }
        //如果字符为字母
        else if (isalpha(ch)) {
          cur_str += ch; //拼接cur_str即可
        }
        //如果字符为 】
        else {
          int times = times_st.top(); //取出数字栈顶元素
          times_st.pop(); //取出后，弹出栈顶元素
          string tmp = ""; //创建一个临时string
          for (int j = 0; j < times; j++) {
            tmp += cur_str; //tmp用来存放复制times次的cur_str
          }
          cur_str = str_st.top(); //取出字符串栈的栈顶元素
          str_st.pop(); //取出后，弹出栈顶元素
          cur_str += tmp; //将tmp拼接到cur_str后面
        }
      }

      return cur_str;
    }
};

int main() {
  string test = "2[abc]3[cd]ef";
  Solution S;
  string res = S.decodeString(test);
  return 0;
}
