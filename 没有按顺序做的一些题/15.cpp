//
// Created by ogier on 24-3-30.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      int k = nums.size() - 1;
      //if smallest number larger than 0 , the sum must > 0
      if (nums[i] > 0)
        continue;
      //need move j & k to get j+k = -i
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          res.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1]) ++j;
          while (j < k && nums[k] == nums[k - 1]) --k;
          ++j;
          --k;
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
    }
    return res;
  }
};