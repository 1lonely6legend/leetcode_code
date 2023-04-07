//
// Created by ogier on 23-4-7.
//
#include <vector>
#include <iostream>

using std::vector;

int removeDuplicates(vector<int> &nums) {
  int j = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != nums[j])
      nums[++j] = nums[i];
  }//双指针
  return j + 1;//返回的是元素个数，不是最后一个元素的下标，所以记得加上1
}

int main() {
  vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int ans = removeDuplicates(nums1);
  std::cout << ans;
  return 0;
}