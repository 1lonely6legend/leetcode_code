//
// Created by ogier on 2023/12/18.
// 53.最大子数组和
#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int> &nums){
    if(nums.size() == 0)
      return 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < nums.size(); ++i){
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      if(dp[i] > res) 
        res = dp[i];
    }
    return res;
  }
};
