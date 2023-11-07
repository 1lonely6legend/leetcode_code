//
// Created by ogier on 2023/11/7.
// 94.二叉树的中序遍历
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
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
 public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode *cur = root;
		while (cur != nullptr || !stk.empty()) {
			if (cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			} else {
				cur = stk.top();
				stk.pop();
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
		return res;
	}
};

class Solution2 {
	vector<int> res;
 public:
	vector<int> inorderTraversal(TreeNode *root) {
		travel(root);
		return res;
	}
	void travel(TreeNode *root) {
		if (root == nullptr) return;
		travel(root->left);
		res.push_back(root->val);
		travel(root->right);
	}
};