//
// Created by ogier on 23-12-18.
// 300.最长增长子序列
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    vector<int> dp(nums.size(), 1);
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > result) result = dp[i]; // 取长的子序列
    }
    return result;
  }
};