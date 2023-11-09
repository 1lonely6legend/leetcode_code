//
// Created by ogier on 2023/11/9.
// 111.二叉树的最小深度
#include<iostream>
#include<queue>
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
	int getdepth(TreeNode *node) {
		if (node == nullptr) return 0;
		int leftdepth = getdepth(node->left);
		int rightdepth = getdepth(node->right);
		if (node->left == nullptr && node->right != nullptr) {
			return 1 + rightdepth;
		}
		if (node->left != nullptr && node->right == nullptr) {
			return 1 + leftdepth;
		}
		int result = 1 + min(leftdepth, rightdepth);
		return result;
	}
	int minDepth(TreeNode *root) {
		return getdepth(root);
	}
};

class Pretravle {
 private:
	int result;
	void getdepth(TreeNode *node, int depth) {
		if (node == nullptr) {
			return;
		}
		if (node->left == nullptr && node->right == nullptr) {
			result = min(result, depth);
		}
		if (node->left)
			getdepth(node->left, depth + 1);
		if (node->right)
			getdepth(node->right, depth + 1);
		return;
	}
 public:
	int minDepth(TreeNode *root) {
		if (root == nullptr)
			return 0;
		int res = INT_MAX;
		getdepth(root, 1);
		return res;
	}
};