//
// Created by ogier on 24-4-11.
//
#include<bits/stdc++.h>
using namespace std;
class Solution2d {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
      dp[i][0] = 1;
    for (int i = 0; i < n; ++i)
      dp[0][i] = 1;

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

class Solution1d {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n);
    for (int i = 0; i < n; ++i)
      dp[i] = 1;

    for (int j = 1; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        dp[i] +=  dp[i - 1];
      }
    }
    return dp[n - 1];
  }
};