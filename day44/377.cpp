//
// Created by ogier on 2023/12/8.
// 377.组合总和Ⅳ
// 本题求的是排列，并不是组合，需要考虑for循环的遍历顺序
#include <vector>
#include <iostream>
using namespace std;
class Solution {
 public:
  int combinationSum4(vector<int> &nums, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 0; i <= target; i++) {
	  for (int j = 0; j < nums.size(); ++j) {
		if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
		  dp[i] += dp[i - nums[j]];
		}
	  }
	}
	return dp[target];
  }
};