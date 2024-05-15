//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> path;
    vector<vector<int> > res;
    void backtracking(vector<int> &nums, int start) {
      res.push_back(path);
      if (start > nums.size())
        return;
      for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
      }
    }
    vector<vector<int> > subsets(vector<int> &nums) {
      backtracking(nums, 0);
      return res;
    }
};
