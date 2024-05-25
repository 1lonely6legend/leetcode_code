//
// Created by ogier on 24-5-15.
//
#include <functional>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  static bool IsPalindrome(string &s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) return false;
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    function<void(int)> dfs = [&](int start) {
      if (start == s.size()) {
        res.emplace_back(path);
        return;
      }
      for (int i = start; i < s.size(); ++i) {
        if (IsPalindrome(s, start, i)) {
          path.emplace_back(s.substr(start, i - start + 1));
          dfs(i + 1);
          path.pop_back();
        }
      }
    };
    dfs(0);
    return res;
  }
};
int main() {
  string s = "aab";
    Solution sol;
  auto res = sol.partition(s);
    for (auto &v : res) {
        for (auto &str : v) {
        printf("%s ", str.c_str());
        }
        printf("\n");
    }
  return 0;
}