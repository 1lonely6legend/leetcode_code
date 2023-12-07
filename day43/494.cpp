//
// Created by ogier on 2023/12/6.
// 494.目标和
#include <vector>
#include <cmath>
using namespace std;
class Solutiondigui {
 public:
  int count = 0;
  void backtracking(vector<int> &nums, int target, int index, int sum) {
	if (index == nums.size()) {
	  if (sum == target)
		count++;
	} else {
	  backtracking(nums, target, index + 1, sum + nums[index]);
	  backtracking(nums, target, index + 1, sum - nums[index]);
	}
  }
  int findTargetSumWays(vector<int> &nums, int target) {
	backtracking(nums, target, 0, 0);
	return count;
  }
};

class Solution1dBag {
 public:
  int count = 0;
  int findTargetSumWays(vector<int> &nums, int target) {
	int sum = 0;
	for (auto a : nums)
	  sum += a;

	if (abs(target) > sum) return 0;
	if ((sum - target) % 2 == 1) return 0;
	int neg = (sum - target) / 2;

	//dp[i]代表，
	vector<int> dp(neg + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
	  for (int j = neg; j >= nums[i]; --j) {
		dp[j] += dp[j - nums[i]];
	  }
	}
	return dp[neg];
  }
};