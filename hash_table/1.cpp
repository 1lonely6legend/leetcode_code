//
// Created by ogier on 2023/5/13.
// 1. 两数之和
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hash_map;
  for (int i = 0; i < nums.size(); ++i) {
    auto iter = hash_map.find(target - nums[i]);
    if (iter != hash_map.end())
      return {iter->second, i};
    hash_map[nums[i]] = i;
  }
  return {};
}

int main() {
  vector<int> nums = {3, 2, 4};
  int target = 6;
  auto ans = twoSum(nums, target);
  for (auto n : ans) {
    std::cout << n << ' ';
  }
  return 0;
}