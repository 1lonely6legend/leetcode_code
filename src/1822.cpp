//
// Created by ogier on 2022/10/27.
//byd最简单的一次

#include <vector>
#include <iostream>

using std::vector;

int arraySign(vector<int> &nums) {
  auto size = nums.size();
  int ans = 1;    //先当全是正数
  for (int i = 0; i < size; ++i) {
    if (nums[i] == 0) return 0; //有一个0 那肯定乘出来也是0
    ans = nums[i] > 0 ? ans : -ans; //要是正数ans正负不变，负数的话ans符号改变
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 0, -1};
  double ans = arraySign(nums);
  std::cout << ans;
  return 0;
}