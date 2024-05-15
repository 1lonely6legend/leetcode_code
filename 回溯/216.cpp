//
// Created by ogier on 24-5-15.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  int count;
  void backtracking(int k, int target, int start) {
    if (count < 0 || path.size() > k)
      return;
    if (count == 0 && path.size() == k) {
      res.push_back(path);
      return;
    }
    for (int i = start; i <= 9; ++i) {
      path.push_back(i);
      count -= i;
      backtracking(k, target, i + 1);
      count += i;
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    count = n;
    backtracking(k, n, 1);
    return res;
  }
};