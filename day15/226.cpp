//
// Created by ogier on 2023/11/8.
// 226.反转二叉树
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
	TreeNode *invertTree(TreeNode *root) {
		queue<TreeNode *> que;
		if (root == nullptr)return nullptr;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *cur = que.front();
				que.pop();
				TreeNode *temp = cur->left;
				cur->left = cur->right;
				cur->right = temp;
				if (cur->left)que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return root;
	}
};