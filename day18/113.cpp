//
// Created by ogier on 2023/11/11.
//113.路径总和Ⅱ
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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
	void traversal(TreeNode *node, int count, vector<int> paths, vector<vector<int>> &res) {
		if (node->left == nullptr && node->right == nullptr) {
			if (count == 0)
				res.push_back(paths);
			return;
		}
		if (node->left) {
			paths.push_back(node->left->val);
			count -= node->left->val;
			traversal(node->left, count, paths, res);
			paths.pop_back();
			count += node->left->val;
		}
		if (node->right) {
			paths.push_back(node->right->val);
			count -= node->right->val;
			traversal(node->right, count, paths, res);
			paths.pop_back();
			count += node->right->val;
		}
	}
	vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
		vector<int> path;
		vector<vector<int>> res;
		if (root == nullptr)return res;
		path.push_back(root->val);
		traversal(root, targetSum - root->val, path, res);
		return res;
	}
};