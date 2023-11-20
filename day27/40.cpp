//
// Created by ogier on 2023/11/19.
// 40.组合总和Ⅱ
/* 相比较于39更难
 要保证用的数字后续不再使用：
 1.需要对数组进行排序，如果相同数组挨着，那么就要一直跳到下一种数字
 2.需要首先对数组进行排序
 */

#include<vector>
#include<algorithm>
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
			if (i > startindex && nums[i] == nums[i - 1]) {
				continue;
			}
			path.push_back(nums[i]);
			count -= nums[i];
			backtracking(nums, path, i + 1, count, res);
			count += nums[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		vector<int> path;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, path, 0, target, res);
		return res;
	}
};

int main() {
	vector<int> test = {10, 1, 2, 7, 6, 1, 5};
	Solution S;
	auto res = S.combinationSum2(test, 8);

	return 0;
}