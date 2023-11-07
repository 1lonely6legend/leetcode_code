//
// Created by ogier on 2023/11/7.
// 145.二叉树的后序遍历
#include <queue>
#include <stack>
#include <vector>
#include<algorithm>
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode *> stk;
		if (root == nullptr) return res;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode *cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->left) stk.push(cur->left);
			if (cur->right) stk.push(cur->right);
		}
		reverse(res.begin(), res.end());
		return res;
	}

};
class Solution2 {
	vector<int> res;
 public:
	vector<int> postorderTraversal(TreeNode *root) {
		travel(root);
		return res;
	}
 private:
	void travel(TreeNode *root) {
		if (root == nullptr) return;
		travel(root->left);
		travel(root->right);
		res.push_back(root->val);
	}
};