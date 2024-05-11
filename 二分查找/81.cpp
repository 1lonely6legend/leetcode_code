//
// Created by ogier on 24-5-11.
//https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/solutions/705486/gong-shui-san-xie-xiang-jie-wei-he-yuan-xtam4
// 和33的区别就是，会有重复数字，在重复数字处分开，会导致分开的两段性质不同，需要缩小r，相比较于leetcode33只更改了16行这一行代码
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    //缩写搜索区间，将末尾可能会出现的重复数字剔除
    while (l < r && nums[0] == nums[r])--r;
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
        return true;
      }
    }
    return false;
  }
};