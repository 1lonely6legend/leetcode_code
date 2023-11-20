//
// Created by ogier on 2023/11/19.
// 39.组合总和
// 这样的话不能每次都从nums的第一个数字开始遍历，可以允许重复，但是每次都要从当前的这个元素遍历
// 只允许重复读取当前的元素
#include<vector>
using namespace std;
class Solution {
 public:
	void backtracking(const vector<int> &nums, vector<int> &path, int startindex, int &count, vector<vector<int>> &res) {
		if (count < 0)
			return;
		if (count == 0) {
			res.push_back(path);
			return;
		}
		for (int i = startindex; i < nums.size(); ++i) {
			path.push_back(nums[i]);
			count -= nums[i];
			backtracking(nums, path, i, count, res);
			count += nums[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<int> path;
		vector<vector<int>> res;
		backtracking(candidates, path, 0, target, res);
		return res;
	}
};

int main() {
	vector<int> test = {2, 3, 6, 7};
	Solution S;
	auto res = S.combinationSum(test, 7);

	return 0;
}