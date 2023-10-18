//
// Created by ogier on 2023/10/17.
// 235.二叉搜索树的最近公共祖先
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
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		while (root) {
			if (root->val > p->val && root->val > q->val) {
				root = root->left;
			} else if (root->val < p->val && root->val < q->val) {
				root = root->right;
			} else return root;
		}
		return nullptr;
	}
};

