//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > res;
    vector<int> path;
    int count = 0;
    function<void(int)> dfs = [&](int start) {
      if(count >= target) {
        if(count == target)
          res.emplace_back(path);
        return;
      }
      for(int i = start; i < candidates.size(); ++i) {
        count += candidates[i];
        path.emplace_back(candidates[i]);
        dfs(i);
        path.pop_back();
        count -= candidates[i];
      }
    };
    dfs(0);
    return res;
  }
};

