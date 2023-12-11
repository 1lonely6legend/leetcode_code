//
// Created by ogier on 2023/12/8.
// 322.零钱兑换
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
	if (amount == 0)
	  return 0;
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < coins.size(); ++i) {
	  for (int j = coins[i]; j <= amount; ++j) {
		if (dp[j - coins[i]] != INT_MAX)
		  dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
	  }
	}
	if (dp[amount] == INT_MAX)
	  return -1;
	return dp[amount];
  }
};