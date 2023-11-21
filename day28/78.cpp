//
// Created by ogier on 2023/11/21.
// 78.子集
// 这个回溯就是在每个节点处都将结果放入res
// 每次向后移动一位
#include<iostream>
#include<vector>
#include<string>
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
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums) {
		res.clear();
		path.clear();
		backtracking(nums, 0);
		return res;
	}
};

int main(){
	Solution S;
	vector<int> test =  {1,2,3};
	auto res = S.subsets(test);
	return 0;
}