//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
      }
    }
    return dp[n];
  }
};