//
// Created by ogier on 2023/10/19.
// 538.把二叉搜索树转换为累加树

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
	TreeNode *convertBST(TreeNode *root) {
		pre = 0;
		traversal(root);
		return root;
	}
 private:
	int pre = 0;
	void traversal(TreeNode *cur) {
		if (cur == nullptr) return;
		traversal(cur->right);
		cur->val += pre;
		pre = cur->val;
		traversal(cur->left);
	}
};