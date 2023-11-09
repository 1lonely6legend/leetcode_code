//
// Created by ogier on 2023/11/9.
// 104.二叉树的最大深度
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
class BFS {
 public:
	int maxDepth(TreeNode *root) {
		int res = 0;
		queue<TreeNode *> que;
		if (root != nullptr) que.push(root);
		while (!que.empty()) {
			res++;
			int size = que.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right)que.push(cur->right);
			}
		}
		return res;
	}
};
class DFS {
 public:
	int getdepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftdepth = getdepth(node->left);       // 左
		int rightdepth = getdepth(node->right);     // 右
		int depth = 1 + max(leftdepth, rightdepth); // 中
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getdepth(root);
	}
};