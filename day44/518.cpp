//
// Created by ogier on 2023/12/8.
// 518.零钱兑换Ⅱ
#include <vector>
#include <iostream>
using namespace std;
class Solution {
 public:
  int change(int amount, vector<int> &coins) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < coins.size(); ++i) {
	  for (int j = coins[i]; j <= amount; ++j) {
		dp[j] += dp[j - coins[i]];
	  }
	}
	return dp[amount];
  }
};