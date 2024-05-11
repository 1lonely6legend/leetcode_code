//
// Created by ogier on 24-5-11.
//
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int length_max = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > length_max) break;
      length_max = max(length_max, nums[i] + i);
    }
    if (length_max >= nums.size() - 1)
      return true;
    else
      return false;
  }
};