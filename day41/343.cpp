//
// Created by ogier on 23-12-2.
// 343.整数拆分
#include <math.h>
#include <vector>
using namespace std;
class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3)return 2;
    if (n == 4) return 4;
    int num_3 = n / 3;
    int num_yu = n % 3;
    if (num_yu == 2) {
      return pow(3, num_3) * 2;
    }
    if (num_yu == 0) {
      return pow(3, num_3);
    }
    if (num_yu == 1) {
      return pow(3, num_3 - 1) * 2 * 2;
    }
    return 0;
  }
};

class SolutionDP {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
      }
    }
    return dp[n];
  }
};

int main() {
  SolutionDP S;
  int res = S.integerBreak(10);
  return 0;
}