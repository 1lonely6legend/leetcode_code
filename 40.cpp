//
// Created by ogier on 2024/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int> &candidates, int target, int sum, int startIndex, vector<bool> &used) {
    if (sum == target) {
      result.emplace_back(path);
      return;
    }
    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i) {
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }
      sum += candidates[i];
      path.emplace_back(candidates[i]);
      used[i] = true;
      backtracking(candidates, target, sum, i + 1, used);
      used[i] = false;
      path.pop_back();
      sum -= candidates[i];
    }

  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<bool> used(candidates.size(), false);
    path.clear();
    result.clear();
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
  }
};