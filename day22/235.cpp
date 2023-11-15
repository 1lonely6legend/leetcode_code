//
// Created by ogier on 2023/11/15.
// 235.二叉搜索树的最近公共祖先
#include <iostream>
#include<stkue>
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
	//可以使用迭代,题目中说明了,P,Q一定存在于二叉树中
	//因为是搜索二叉树,每次通过比较值,就可以得到查找的方向 L/R?
 public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		int rightvalue = max(p->val, q->val);
		int leftvalue = min(p->val, q->val);
		TreeNode *cur = root;
		while (cur != nullptr) {
			if (cur->val == rightvalue || cur->val == leftvalue) {
				return cur;
			}
			if (cur->val > leftvalue && cur->val < rightvalue) {
				return cur;
			}
			if (cur->val > rightvalue)
				cur = cur->left;
			else if (cur->val < leftvalue)
				cur = cur->right;
		}
		return nullptr;
	}
};

class Solution1 {
 public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root->val > p->val && root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		} else if (root->val < q->val && root->val < p->val) {
			return lowestCommonAncestor(root->right, q, p);
		} else return root;
	}
};