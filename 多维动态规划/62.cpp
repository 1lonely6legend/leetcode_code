//
// Created by ogier on 24-5-16.
//
#include <vector>
using namespace std;
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) dp[i] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] = dp[j-1]+dp[j];
      }
    }
    return dp[n-1];
  }
};