//
// Created by ogier on 2023/5/17.
// 209.长度最小的子数组
// https://www.bilibili.com/video/BV1tZ4y1q7XE
// 滑动窗口的最关键的就是如何去移动起始位置
#include <iostream>
#include <vector>
using std::vector;


int minSubArrayLen(int s, vector<int>& nums) {
  int result = INT32_MAX;
  int sum = 0; // 滑动窗口数值之和
  int i = 0; // 滑动窗口起始位置
  int subLength = 0; // 滑动窗口的长度
  //是去遍历终止位置,而对于起始位置,我们要不断地去移动
  for (int j = 0; j < nums.size(); j++) {
    sum += nums[j];
    // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
    while (sum >= s) {
      subLength = (j - i + 1); // 取子序列的长度
      result = result < subLength ? result : subLength;
      sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
    }
  }
  // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
  return result == INT32_MAX ? 0 : result;
}

int main() {
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  std::cout << minSubArrayLen(target, nums);
  return 0;
}
