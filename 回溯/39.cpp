//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  int count ;
  void backtracking(vector<int> &candidates, int target, int start) {
    if (count < 0)
      return;
    if (count == 0)
      res.push_back(path);
    for (int i = start; i < candidates.size(); ++i) {
      count -= candidates[i];
      path.push_back(candidates[i]);
      backtracking(candidates,target,i);//因为一个数字可以重复使用，所以这里传入的参数还是i
      path.pop_back();
      count += candidates[i];
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    path.clear();
    res.clear();
    count = target;
    backtracking(candidates, target, 0);
    return res;
  }
};
