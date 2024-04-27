//
// Created by ogier on 2023/12/11.
// 337.打家劫舍Ⅲ
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

class Solution {
 public:
  int rob(TreeNode *root) {
	pair<int, int> res = robTree(root);
	return max(res.first, res.second);
  }
  pair<int, int> robTree(TreeNode *cur) {
	if (cur == nullptr) return {0, 0};
	auto left = robTree(cur->left);
	auto right = robTree(cur->right);
	int val1 = cur->val + left.first + right.first;
	int val2 = max(left.first, left.second) + max(right.first, right.second);
	return {val2, val1};
  }
};
