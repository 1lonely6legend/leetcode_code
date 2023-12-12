//
// Created by ogier on 2023/12/12.
// 121.买卖股票的最佳时机
#include <vector>
#include <iostream>
using namespace std;
class SolutionGreed {
 public:
  int maxProfit(vector<int>& prices) {
	int low = INT_MAX;
	int result = 0;
	for (int i = 0; i < prices.size(); i++) {
	  low = min(low, prices[i]);  // 取最左最小价格
	  result = max(result, prices[i] - low); // 直接取最大区间利润
	}
	return result;
  }
};

class SolutionDP {
 public:
  int maxProfit(vector<int>& prices) {
	int len = prices.size();
	if (len == 0) return 0;
	vector<vector<int>> dp(len, vector<int>(2));
	dp[0][0] -= prices[0];
	dp[0][1] = 0;
	for (int i = 1; i < len; i++) {
	  dp[i][0] = max(dp[i - 1][0], -prices[i]);
	  dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
	}
	return dp[len - 1][1];
  }
};