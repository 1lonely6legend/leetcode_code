//
// Created by ogier on 24-5-11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    vector<int> res;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        int i = mid, j = mid;
        //这里需要提前判断，防止超出范围
        while (i > 0 && nums[i - 1] == target) --i;
        while (j < nums.size() - 1 && nums[j + 1] == target) ++j;
        res.emplace_back(i);
        res.emplace_back(j);
        return res;
      }
    }
    return {-1, -1};
  }
};