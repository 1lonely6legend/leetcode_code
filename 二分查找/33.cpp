//
// Created by ogier on 24-5-11.
//https://leetcode.cn/problems/search-in-rotated-sorted-array/solutions/577298/shua-chuan-lc-yan-ge-ologn100yi-qi-kan-q-xifo
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    //二分法的本质是两段性质不相等，根据这个左边和右边跟nums[0]大小关系，进行查找
    //最后l是分界点
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] >= nums[0]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (target >= nums[0]) {
      r = l - 1;//注意这里要先通过l把r确定了
      l = 0;
    } else {
      r = n - 1;
    }
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
