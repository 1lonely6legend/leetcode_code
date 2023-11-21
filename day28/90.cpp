//
// Created by ogier on 2023/11/21.
// 90.子集Ⅱ
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> res;
	vector<int> path;
 public:
	void backtracking(const vector<int> &nums, int startIndex) {
		res.push_back(path);
		if (startIndex == nums.size())
			return;
		for (int i = startIndex; i < nums.size(); ++i) {
			if (i > startIndex && nums[i] == nums[i - 1])
				continue;
			path.push_back(nums[i]);
			backtracking(nums, i+1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		backtracking(nums, 0);
		return res;
	}
};

int main() {
	vector<int> test = {1, 2, 2};
	Solution S;
	auto res = S.subsetsWithDup(test);
	return 0;
}