//
// Created by ogier on 23-4-20.
// https://leetcode.cn/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

//看md

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); ++i) {
    map[nums[i]] = i;
  }
  for (int i = 0; i < nums.size(); ++i) {
    auto iter = map.find(target - nums[i]);
    if (iter != map.end() && iter->second != i) {
      return {i, iter->second};
    }
  }
  return {};
}

int main() {
  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> ans = twoSum(nums, target);
  for (auto n : ans) {
    std::cout << n << ' ';
  }
  return 0;
}
