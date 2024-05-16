//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
 public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
class Solution2{
public:
  int climbStairs(int n) {
    int ppre = 1;
    int pre = 1;
    int res = 0;
    if(n == 1)
      return 1;
    while(--n) {
      res = ppre+pre;
      ppre = pre;
      pre = res;
    }
    return res;
  }
};