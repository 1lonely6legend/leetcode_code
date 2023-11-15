//
// Created by ogier on 2023/11/14.
// 二叉搜索树中的众数
#include <iostream>
#include<queue>
#include<stack>
#include <algorithm>
#include<map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
	map<int, int> map1;
	void Traversal(TreeNode *node, vector<int> &nums) {
		if (node == nullptr) return;
		if (node->left) Traversal(node->left, nums);
		map1[node->val]++;
		if (node->right) Traversal(node->right, nums);
	}
	vector<int> findMode(TreeNode *root) {
		vector<int> nums;
		Traversal(root, nums);
		vector<pair<int, int>> pair(map1.begin(), map1.end());
		sort(pair.begin(), pair.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
		int num = pair[0].second;
		vector<int> res;
		for (auto iter : pair) {
			if (iter.second != num)
				break;
			res.push_back(iter.first);
		}
		return res;
	}
};

void test(vector<int> nums) {
	map<int, int> map1;
	for (auto a : nums)
		map1[a]++;
	vector<pair<int, int>> pair(map1.begin(), map1.end());
	sort(pair.begin(), pair.end(), [](const auto &a, const auto &b) { return a.second > b.second; });

}

int main() {
	vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5, 6};
	test(nums);
	return 0;
}