//
// Created by ogier on 2023/11/17.
// 77.组合
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	//无剪枝
 public:
	vector<int> path;
	vector<vector<int>> res;
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = startIndex; i <= n; ++i) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return res;
	}
};
class Solution2 {
	//进行剪枝
 public:
	vector<int> path;
	vector<vector<int>> res;
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = startIndex; i <= n -(k-path.size())+1; ++i) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return res;
	}
};

