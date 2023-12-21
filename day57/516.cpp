//
// Created by ogier on 2023/12/21.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int res = 0;
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    for (int i = 0; i < s.length(); ++i)
      dp[i][i] = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
      for (int j = i + 1; j < s.length(); ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][s.size() - 1];
  }
};