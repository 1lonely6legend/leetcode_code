//
// Created by ogier on 2023/11/7.
// 144.二叉树的前序遍历
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

//迭代版本
class Solution1 {
 public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode *> stk;
		if (root == nullptr) return {};
		stk.push(root);
		while (!stk.empty()) {
			TreeNode *cur = stk.top();
			stk.pop();
			res.emplace_back(cur->val);
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return res;
	}
};

class Solution2 {
	vector<int> res;
 public:
	vector<int> preorderTraversal(TreeNode *root) {
		travel(root);
		return res;
	}
 private:
	void travel(TreeNode *root) {
		if (root == nullptr) return;
		res.push_back(root->val);
		travel(root->left);
		travel(root->right);
	}
};