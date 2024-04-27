//
// Created by ogier on 2023/12/11.
// 213.打家劫舍Ⅱ
#include <vector>
using namespace std;
class Solution {
 public:
  int rob(vector<int> &nums) {
    int size = 0;
    if (nums.size() == 1) return nums[0];
    int res1 = robrange(nums, 0, nums.size() - 2);
    int res2 = robrange(nums, 1, nums.size() - 1);
    return max(res1, res2);
  }
  // 198.打家劫舍的逻辑
  int robrange(vector<int> &nums, int start, int end) {
    if (end == start) return nums[start];
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start+1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; ++i) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
  }
};