//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    vector<int> dp(nums.size(), 1);
    int res = 0;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > res) res = dp[i];
    }
    return res;
  }
};