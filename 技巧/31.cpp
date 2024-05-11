//
// Created by ogier on 24-5-11.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &nums) {
    //需要在尽量靠右的位置寻找第一个下降的位置
    //然后在尽量靠右的位置寻找第一个比下降位置大的数
    //交换这两个数
    //然后将下降位置右边的数逆序
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[i] >= nums[j])
        j--;
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};