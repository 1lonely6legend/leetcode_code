//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > res;
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
      res.emplace_back(path);
      if(path.size() == nums.size()) {
        return;
      }
      for(int i  = start; i < nums.size(); ++i) {
        path.emplace_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
      }
    };
    dfs(0);
    return res;
  }
};
