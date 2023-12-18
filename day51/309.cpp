//
// Created by ogier on 23-12-18.
// 309.买卖股票的最佳时机含冷冻期
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(4, 0));

    //0持有股票、1保持卖出股票、2今天卖出股票、3冷冻期
    dp[0][0] -= prices[0]; // 持股票
    for (int i = 1; i < n; i++) {
      //买入股票状态可以从:前一天就是买入状态,前一天冷冻结束后买的股票,前一天卖出股票状态后买的股票
      dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
      //保持卖出股票只能由之前就是保持卖出 或者 冷冻期转变而来
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
      dp[i][2] = dp[i - 1][0] + prices[i];
      //冷冻期由前一天卖出股票转变而来
      dp[i][3] = dp[i - 1][2];
    }
    return max(dp[n - 1][3], max(dp[n - 1][1], dp[n - 1][2]));
  }
};