//
// Created by ogier on 2023/5/15.
// 167. 两数之和 II - 输入有序数组
// 有序数组加上常量级内存空间,我猜是二分查找,,原来是双指针
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solution/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
        return {left + 1, right + 1};
        } else if (sum < target) {
        ++left;
        } else {
        --right;
        }
    }
    return {-1, -1};
}

int main() {
  vector<int> nums = {2,7,11,15,21,98};
  int target = 22;
  auto ans = twoSum(nums, target);
  for (auto n : ans) {
    std::cout << n << ' ';
  }
  return 0;
}

