//
// Created by ogier on 2023/11/17.
// 216.组合总和III
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  int sum = 0;
  void backtracking(int n, int k, int startindex) {
    if (path.size() == k) {
      if (sum == n) {
        res.push_back(path);
      }
      return;
    }
    for (int i = startindex; i < 10; ++i) {
      path.push_back(i);
      sum += i;
      backtracking(n, k, i + 1);
      sum -= i;
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(n, k, 1);
    return res;
  }
};