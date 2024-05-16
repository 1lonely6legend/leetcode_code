//
// Created by ogier on 24-5-16.
//
#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  bool canPartition(std::vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;
    vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    if(dp[target] == target)return true;
    return false;
  }
};