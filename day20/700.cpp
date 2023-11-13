//
// Created by ogier on 2023/11/13.
// 二叉搜索树中的搜索
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
	TreeNode *searchBST(TreeNode *root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val == val) return root;
		if (root->val > val) return searchBST(root->left, val);
		if (root->val < val) return searchBST(root->right, val);
		return nullptr;
	}
};