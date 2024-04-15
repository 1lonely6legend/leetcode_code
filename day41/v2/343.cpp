//
// Created by ogier on 24-4-11.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]));
      }
    }
    return dp[n];
  }
};