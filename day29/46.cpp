//
// Created by ogier on 2023/11/22.
// 36.全排列
#include<vector>
using namespace std;

class Solution {
 public:
  vector<int> path;
  vector<vector<int>> res;
  void backtracking(const vector<int> &nums, vector<int> &used) {
	if (path.size() == nums.size()) {
	  res.push_back(path);
	  return;
	}
	for (int i = 0; i < nums.size(); ++i) {
	  if (used[i] == 1)
		continue;
	  path.push_back(nums[i]);
	  used[i] = 1;
	  backtracking(nums, used);
	  path.pop_back();
	  used[i] = 0;
	}
  }
  vector<vector<int>> permute(vector<int> &nums) {
	vector<int> used(nums.size(),0);
	backtracking(nums, used);
	return res;
  }
};

int main() {
  vector<int> test = {1, 2, 3};
  Solution S;
  auto res = S.permute(test);
  return 0;
}
