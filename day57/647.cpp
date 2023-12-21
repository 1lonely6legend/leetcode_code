//
// Created by ogier on 23-12-21
//
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int countSubstrings(string s) {
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
    int res = 0;
    int size = s.length();
    for (int i = size - 1; i >= 0; --i) {
      for (int j = i; j < size; ++j) {
        if (s[i] == s[j]) {
          if (j - i <= 1) {
            res++;
            dp[i][j] = true;
          } else if (dp[i + 1][j - 1]) {
            res++;
            dp[i][j] = true;
          }
        }
      }
    }
    return res;
  }
};
