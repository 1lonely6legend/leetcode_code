//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i - 1] == nums[i]) continue;
      if (nums[i] > 0) continue;
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          res.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j + 1] == nums[j]) ++j;
          while (j < k && nums[k - 1] == nums[k]) --k;
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