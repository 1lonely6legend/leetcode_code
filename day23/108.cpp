//
// Created by ogier on 2023/11/16.
// 108.将有序数组转换为二叉搜索树
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
	TreeNode *gen(const vector<int> &nums, int left, int right) {
		//想明白递归到最后究竟返回什么, 返回的是不存在的nullptr
		if (left > right)
			return nullptr;
		int mid = left + (right - left) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = gen(nums, left, mid);
		root->right = gen(nums, mid + 1, right);
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		int left = 0;
		int right = nums.size();
		return gen(nums, left, right);
	}
};