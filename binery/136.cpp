//
// Created by ogier on 23-4-26.
// 136. 只出现一次的数字
// https://leetcode.cn/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
// 没有做出来,充分利用题目中所给的信息,一个字母最多出现两次,
// 使用异或运算!!!
// 异或运算符号^
#include <iostream>
#include <vector>
using std::vector;

int singleNumber(vector<int> &nums) {
  int res = nums[0];
  for (auto iter = nums.begin() + 1; iter < nums.end(); ++iter) {
    res ^= *iter;
  }
  return res;
}

int main() {
  vector<int> nums = {2, 2, 1};
  std::cout << singleNumber(nums);
  return 0;
}

