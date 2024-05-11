//
// Created by ogier on 2024/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  vector<vector<int>> res;
  vector<int> path;
  void backtracking(vector<int> &nums, vector<bool> &used) {
    // 此时说明找到了一组
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == true) continue; // path里已经收录的元素，直接跳过
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    res.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
  }
};