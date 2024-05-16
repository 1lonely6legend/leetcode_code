//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int findLengthOfLCIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        dp[i] += dp[i - 1];
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};