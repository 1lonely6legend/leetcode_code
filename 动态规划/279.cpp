//
// Created by ogier on 24-5-15.
//完全平方数就是物品（可以无限件使用），凑个正整数n就是背包，问凑满这个背包最少有多少物品？
#include <climits>
#include <vector>
using namespace std;
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {//相当于先遍历物品
      for (int j = 1; j * j <= i; ++j) {//注意这里<=，相当于后遍历背包
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

int main() {
  Solution S;
  auto res = S.numSquares(12);
  return 0;
}