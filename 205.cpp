//
// Created by ogier on 2023/4/19.
// 205. 同构字符串
// https://leetcode.cn/problems/isomorphic-strings/?envType=study-plan-v2&id=top-interview-150
// tmd  没写出来
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;

bool isIsomorphic(string s, string t) {
  unordered_map<char, char> s2t;
  unordered_map<char, char> t2s;
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    char x = s[i], y = t[i];
    //unordered_map的count方法可以返回指定键是否出现,如果已有该键返回1,没有则返回0
    if ((s2t.count(x) && s2t[x] != y) //如果之前就已经遇到x,并且对应另一个字符
    || (t2s.count(y) && t2s[y] != x)) //如果之前就有y,并且对应另一个字符
    {
      return false;
    }
    s2t[x] = y;
    t2s[y] = x;
  }
  return true;
}

int main() {
  string s1 = {"aa"};
  string s2 = {"aab"};
  bool ans;
  ans = isIsomorphic(s1, s2);
  std::cout << ans;
  return 0;
}

