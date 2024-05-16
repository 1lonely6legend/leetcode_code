//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int countSubstrings(string s) {
    //布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int res = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
        if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
          res++;
          dp[i][j] = true;
        }
      }
    }
    return res;
  }
};
class Solution2 {
 public:
  int countSubstrings(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      result += extend(s, i, i, s.size());    // 以i为中心
      result += extend(s, i, i + 1, s.size());// 以i和i+1为中心
    }
    return result;
  }
  int extend(const string &s, int i, int j, int n) {
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
      i--;
      j++;
      res++;
    }
    return res;
  }
};