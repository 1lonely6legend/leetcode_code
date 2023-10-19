//
// Created by ogier on 2023/10/19.
// 669.修剪二叉搜索树

//根据给定范围修剪二叉树,首先找到两个节点,把low左子树,和high右子树全部抛弃

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
			: val(x), left(left), right(right) {}
};

class Solution {
 public:
	TreeNode *trimBST(TreeNode *root, int low, int high) {
		if (root == nullptr) return nullptr;
		if (root->val < low) return trimBST(root->right, low, high);
		if (root->val > high) return trimBST(root->left, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};