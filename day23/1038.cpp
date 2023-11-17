//
// Created by ogier on 2023/11/16.
// 1038.从二叉搜索树到更大和树
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
	long sum;
	void traversal(TreeNode *node) {
		if (node == nullptr)return;
		traversal(node->right);
		sum += node->val;
		node->val = sum;
		traversal(node->left);
	}
	TreeNode *bstToGst(TreeNode *root) {
		sum = 0;
		traversal(root);
		return root;
	}
};
