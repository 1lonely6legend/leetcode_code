//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> path;
    vector<vector<int> > res;
    void backtracking(vector<int> &nums, vector<int> &used) {
      if (path.size() == nums.size()) {
        res.emplace_back(path);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (used[i] == true)continue;
        used[i] = 1;
        path.emplace_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = 0;
      }
    }
    vector<vector<int> > permute(vector<int> &nums) {
      path.clear();
      res.clear();
      vector<int> used(nums.size(), 0);
      backtracking(nums, used);
      return res;
    }
};
int main() {
  vector<int> nums = {1, 2, 3};
  Solution S;
  auto res = S.permute(nums);
  return 0;
}
