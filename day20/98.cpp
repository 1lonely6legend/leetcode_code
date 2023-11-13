//
// Created by ogier on 2023/11/13.
// 验证二叉搜索树
#include <iostream>
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
	void traversal(TreeNode *root, vector<int> &nums) {
		if (root == nullptr) return;
		traversal(root->left, nums);
		nums.push_back(root->val);
		traversal(root->right, nums);
	}
	bool isValidBST(TreeNode *root) {
		vector<int> nums;
		traversal(root, nums);
		int temp = nums[0];
		for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
			//注意这里是小于等于 不是小于
			if (*iter <= temp)
				return false;
			temp = *iter;
		}
		return true;
	}
};

int main() {
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	Solution S;
	auto a = S.isValidBST(root);
	return 0;
}