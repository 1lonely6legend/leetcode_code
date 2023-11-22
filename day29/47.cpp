//
// Created by ogier on 2023/11/22.
// 47.全排列Ⅱ
#include<vector>
#include<algorithm>
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
	  if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
		continue;
	  }
	  if (used[i] == 0) {
		used[i] = 1;
		path.push_back(nums[i]);
		backtracking(nums, used);
		used[i] = 0;
		path.pop_back();
	  }
	}
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	vector<int> used(nums.size(), 0);
	backtracking(nums, used);
	return res;
  }
};
int main() {
  vector<int> test = {1, 1, 2};
  Solution S;
  auto res = S.permuteUnique(test);
  return 0;
}