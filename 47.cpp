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
      // 如果同一树层nums[i - 1]使用过则直接跳过
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
        continue; // path里已经收录的元素，直接跳过
      if (used[i] == false) {
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    res.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return res;
  }
};