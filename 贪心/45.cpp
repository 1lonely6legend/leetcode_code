//
// Created by ogier on 24-5-11.
//
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int> &nums) {
    if(nums.size() == 1)  return 0;//注意当长度为0时，返回0，直接走到终点
    int cur_range = 0;
    int next_range = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      next_range = max(nums[i] + i, next_range);
      if (i == cur_range) {
        cur_range = next_range;
        res++;
        if (cur_range >= nums.size() - 1)break;
      }
    }
    return res;
  }
};