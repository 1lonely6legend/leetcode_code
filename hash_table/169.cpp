//
// Created by ogier on 23-4-12.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;

int majorityElement(vector<int> &nums) {
  std::unordered_map<int, int> counts;
  int majority = 0, cnt = 0;
  for (int num : nums) {
    ++counts[num];
    if (counts[num] > cnt) {
      majority = num;
      cnt = counts[num];
    }
  }
  return majority;
}

int main() {
  vector<int> nums1 = {0, 0, 0, 0, 4, 4, 5};
  int ans = majorityElement(nums1);
  std::cout << ans;
  return 0;
}