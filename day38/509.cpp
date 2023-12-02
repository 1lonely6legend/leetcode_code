//
// Created by ogier on 23-12-1.
// 509. 斐波那契数
#include<vector>
using std::vector;
class Solution {
 public:
  int fib(int n) {
    //递归解法，时间复杂度O（2^N），太高
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    return fib(n - 1) + fib(n - 2);
  }
};

class SolutionDP {
  //使用动态规划计算，时间复杂度O（N）
 public:
  int fib(int n) {
    if (n <= 1) return n;
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int sum = dp[0]+dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
    }
    return dp[1];
  }
};
