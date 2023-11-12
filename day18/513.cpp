//
// Created by ogier on 2023/11/11.
// 513.找树左下角的值
#include<iostream>
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
	int findBottomLeftValue(TreeNode *root) {
		queue<TreeNode *> que;
		int res;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			res = que.front()->val;
			for (int i = 0; i < size; ++i) {
				TreeNode *cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return res;
	}
};

class Solution2 {
 public:
	int maxDepth = INT_MIN;
	int res;
	void travsersal(TreeNode *root, int depth) {
		if (root->left == nullptr && root->right == nullptr) {
			if (depth > maxDepth) {
				maxDepth = depth;
				res = root->val;
			}
			return;
		}
		if (root->left) {
			depth++;
			travsersal(root->left, depth);
			depth--;
		}
		if (root->right) {
			depth++;
			travsersal(root->right, depth);
			depth--;
		}
		return;
	}
	int findBottomLeftValue(TreeNode *root) {
		travsersal(root, 0);
		return res;
	}
};