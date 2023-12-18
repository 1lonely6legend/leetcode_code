//
// Created by ogier on 23-12-18.
// 714.买卖股票的最佳时机含手续费
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int> &prices, int fee) {
    if (prices.size() == 0)
      return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
  }
};