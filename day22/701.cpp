//
// Created by ogier on 2023/11/15.
// 701.二叉搜索树中的插入操作
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
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		if (root == nullptr) return new TreeNode(val);
		if (root->val > val) root->left = insertIntoBST(root->left, val);
		if (root->val < val) root->right = insertIntoBST(root->right, val);
		return root;
	}
};