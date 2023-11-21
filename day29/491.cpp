//
// Created by ogier on 23-11-21.
// 491.递增子序列
// 首先把题目意思搞明白
// 什么是递增子序列,可以剔除中间的数是递增的就可以,但是数和数之间的相对位置不能变化
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  void backtracking(const vector<int> &nums, int start) {
    if (path.size() > 1) {
      res.push_back(path);
    }
    unordered_set<int> uset;
    for (int i = start; i < nums.size(); ++i) {
      if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
        //如果现在现在数字对于path递减,或者这个数字这一层递归已经用过了,就找下一个数字
        continue;
      uset.insert(nums[i]);
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    backtracking(nums, 0);
    return res;
  }
};