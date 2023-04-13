//
// Created by ogier on 2023/4/13.
// 189. 轮转数组
#include <vector>
#include <iostream>

using std::vector;

void reverse(vector<int>& nums, int start, int end) {
  while (start < end) {
    std::swap(nums[start], nums[end]);
    start += 1;
    end -= 1;
  }
}
void rotate(vector<int>& nums, int k) {
  k %= nums.size();
  reverse(nums, 0, nums.size() - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, nums.size() - 1);
}

int main() {
  vector<int> nums1 = {1,2,3};
  rotate(nums1, 1);
  for (int num : nums1)
    std::cout << num;
  return 0;
}