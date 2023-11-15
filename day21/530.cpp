//
// Created by ogier on 2023/11/14.
// 二叉搜索树的最小绝对差
#include <iostream>
#include<queue>
#include<stack>
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
	void Traversal(TreeNode *node, vector<int> &nums) {
		if (node == nullptr) return;
		if (node->left) Traversal(node->left, nums);
		nums.push_back(node->val);
		if (node->right) Traversal(node->right, nums);
	}
	int getMinimumDifference(TreeNode *root) {
		vector<int> nums;
		Traversal(root, nums);
		int res = INT_MAX;
		for (int i = 0, j = 1; j < nums.size(); ++i, ++j) {
			int temp = abs(nums[j] - nums[i]);
			res = res < temp ? res : temp;
		}
		return res;
	}
};

class Solution2 {
 public:
	int res = INT_MAX;
	TreeNode *pre = nullptr;
	void traversal(TreeNode *node) {
		if (node == nullptr) return;
		traversal(node->left);
		if (pre != nullptr)
			res = min(res, node->val - pre->val);
		pre = node;
		traversal(node->right);
	}
	int getMinimumDifference(TreeNode *root) {
		traversal(root);
		return res;
	}
};

class Solution3 {
 public:
	int getMinimumDifference(TreeNode *root) {
		stack<TreeNode *> st;
		TreeNode *cur = root;
		TreeNode *pre = nullptr;
		int res = INT_MAX;
		while (cur != nullptr || !st.empty()) {
			if (cur != nullptr) {
				st.push(cur);
				cur = cur->left;
			} else {
				cur = st.top();
				st.pop();
				if (pre != nullptr)
					res = min(res, cur->val - pre->val);
				pre = cur;
				cur = cur->right;
			}
		}
		return res;
	}
};













