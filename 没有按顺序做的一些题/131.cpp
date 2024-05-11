//
// Created by ogier on 2024/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
 public:
  vector<vector<string>> res;
  vector<string> path;
  bool panduan(string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }
  void backtracking(string &s, int startIndex) {
    if (startIndex >= s.size()) {
      res.emplace_back(path);
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      if (panduan(s, startIndex, i)) {
        path.push_back(s.substr(startIndex, i - startIndex + 1));
      } else {
        continue;
      }
      backtracking(s, i + 1);
      path.pop_back();
    }
  }
  vector<vector<string>> partition(string s) {
    res.clear();
    path.clear();
    backtracking(s, 0);
    return res;
  }
};