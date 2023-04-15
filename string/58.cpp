//
// Created by ogier on 2023/4/15.
// 58. 最后一个单词的长度
#include <iostream>
#include <string>

using std::string;

int lengthOfLastWord(string s) {
  int ans = 0;
  auto iter = s.end() - 1;//s当中的最后一个字符
    while (*iter == ' ')//如果有空格就将指针移动至最后一个字母处
      --iter;//最后结束时 iter指向最后一个单词的最后一个字母
  while (iter >= s.begin() && *iter != ' ') {//想清楚终止条件是什么
    //一开始写的while (iter != s.begin() && *iter != ' ')
    ++ans;
    --iter;
  }
  return ans;
}

int main() {
  string s = {"   fly me   to   the moon  "};
  int ans = lengthOfLastWord(s);
  std::cout << ans;
  return 0;
}
