//
// Created by ogier on 23-12-1.
// 70.爬楼梯
class Solution {
 public:
  int climbStairs(int n) {
    //递归太慢了，直接超时
    if (n == 1)
      return 1;
    else if (n == 2)
      return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

class SolutionDP {
 public:
  int climbStairs(int n) {
    if (n <= 2)return n;
    int dp[2];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 3; i <= n; ++i) {
      int sum = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
    }
    return dp[1];
  }
};

int main() {
  SolutionDP S;
  auto res = S.climbStairs(37);
  return 0;
}