//
// Created by ogier on 24-5-15.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
 private:
  vector<string> path;
  vector<vector<string>> res;
  void backtrack(string &s, int start) {
    if (start >= s.size()) {
      res.push_back(path);
    }
    for (int i = start; i < s.size(); ++i) {
      if (huiwen(s,start,i)) {
        string str = s.substr(start,i-start+1);
        path.push_back(str);
      }else {
        continue;
      }
      backtrack(s,i+1);
      path.pop_back();
    }
  }
  bool huiwen(const string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }

 public:
  vector<vector<string>> partition(string s) {
    path.clear();
    res.clear();
    backtrack(s, 0);
    return res;
  }
};