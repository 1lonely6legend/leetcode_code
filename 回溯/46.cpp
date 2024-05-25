//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int> > res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    function<void()> dfs = [&]() {
      if (path.size() == nums.size()) {
        res.emplace_back(path);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if(used[i]) continue;
        path.emplace_back(nums[i]);
        used[i] = true;
        dfs();
        used[i] = false;
        path.pop_back();
      }
    };
    dfs();
    return res;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution S;
  auto res = S.permute(nums);
  return 0;
}
