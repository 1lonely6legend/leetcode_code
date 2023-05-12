//
// Created by ogier on 2023/5/12.
// 151. 反转字符串中的单词 一次过,见md
#include <iostream>
#include <algorithm>
using std::string;

string reverseWords(string s) {
  int size = s.size();
  string res;//初始化结果数组
  int i = size - 1;//size前一个下标才有东西
  while (i >= 0) {//从最后遍历到最前
    if (s.at(i) == ' ')
      //如果有空位直接就while跳过
      while (i >= 1 && s.at(i) == ' ')
        --i;
    //定义快指针
    int fast = i;
    //首先保证不越界,如果前一个为空格就停住
    while (fast >= 1 && s.at(fast - 1) != ' ')
      --fast;
    //将这一段加上一个空格,放到答案里
    res += s.substr(fast, i - fast + 1) + ' ';
    i = fast - 1;//将遍历指针,放到fast前面的空格上
  }
  //走完上面,如果最前面,有空格,那么会算到最后一个单词里,所以把答案最前的空格全部pop
  while (*(res.end() - 1) == ' ')
    res.pop_back();
  return res;
}

int main() {
  string s = "  hello world  ";
  std::cout << reverseWords(s);
  return 0;
}