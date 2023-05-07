//
// Created by ogier on 2023/5/7.
// 238. 除自身以外数组的乘积
// 真好,第一次中等直接有思路一遍ac
// 写了题解,直接去leetcode看思路吧
#include <iostream>
#include <vector>
using std::vector;

//一遍过,正序和倒叙乘两次,每次把结果保存在答案数组里,两次遍历的数乘起来就是答案
vector<int> productExceptSelf(vector<int> &nums) {
  //首先把答案数组的空间确定并申请出来
  int size = nums.size();
  vector<int> res;
  res.resize(size);
  //保存从前往后,从后往前累计乘的值,初始乘积是1不是0
  int front = 1, rear = 1;
  //正序相乘
  for (int i = 0; i < size; ++i) {
    res[i] = front;
    front *= nums[i];
  }
  //倒序相乘
  for (int i = size - 1; i >= 0; --i) {
    res[i] *= rear;
    rear *= nums[i];
  }
  return res;
}
int main() {
  vector<int> nums = {-1,1};
  vector<int> res = productExceptSelf(nums);
  for (auto i : res) {
    std::cout << i << " ";
  }
  return 0;
}