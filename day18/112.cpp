//
// Created by ogier on 2023/11/11.
// 112.路径总和
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
	//注意需要使用long sum
	bool traversal(TreeNode *node, int sum) {
		if (node->left == nullptr && node->right == nullptr) {
			if (sum == 0)
				return true;
			else
				return false;
		}
		if (node->left) {
			sum -= node->left->val;
			if (traversal(node->left, sum)) return true;
			sum += node->left->val;
		}
		if (node->right) {
			sum -= node->right->val;
			if (traversal(node->right, sum)) return true;
			sum += node->right->val;
		}
		return false;
	}
	bool hasPathSum(TreeNode *root, int targetSum) {
		if (root == nullptr) return false;
		return traversal(root, targetSum - root->val);
	}
};