//
// Created by ogier on 2023/4/19.
// 290. 单词规律 是205的升级版
// https://leetcode.cn/problems/word-pattern/?envType=study-plan-v2&id=top-interview-150
// 感觉思想和205差不多,把string当成char即可
#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::string;
using std::vector;

bool wordPattern(string pattern, string s) {
  unordered_map<char, string> p2s;
  unordered_map<string, char> s2p;
  vector<string> s_words;
  int tmp = 0;
  for (int i = 0; i < s.size(); ++i) {
    tmp = i;
    while (s[i] != ' '&& i<s.size()) ++i;
    s_words.push_back(s.substr(tmp, i-tmp));
    //substr()第二个参数是长度,不是截至位置的下标!!!!!!
  }
  if (pattern.size() != s_words.size()) return false;
  for (int i = 0; i < pattern.size(); ++i) {
    if (p2s.count(pattern[i]) && p2s[pattern[i]] != s_words[i]
        || s2p.count(s_words[i]) && s2p[s_words[i]] != pattern[i]) {
      return false;
    }
    p2s[pattern[i]] = s_words[i];
    s2p[s_words[i]] = pattern[i];
  }
  return true;
}

int main() {
  string s1 = {"abba"};
  string s2 = {"dog cat cat dog"};
  bool ans;
  ans = wordPattern(s1, s2);
  std::cout << ans;
  return 0;
}

