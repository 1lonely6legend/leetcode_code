//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
 public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    if (nums.size() == 1) return nums[0];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
  }
};
class Solution2 {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    int a = nums[0];
    int b = max(nums[0], nums[1]);
    int res = b;//如果要是不使用dp数组，那么这里初始化的时候就要是b，也就是dp[1]
    for (int i = 2; i < nums.size(); ++i) {
      res = max(b, a + nums[i]);
      a = b;
      b = res;
    }
    return res;
  }
};