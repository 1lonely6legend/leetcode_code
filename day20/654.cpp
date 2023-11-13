//
// Created by ogier on 2023/11/13.
// 最大二叉树
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

class Solution1 {
 public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		if (nums.size() == 0)return nullptr;
		int maxIndex = 0;
		int maxValue = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > maxValue) {
				maxValue = nums[i];
				maxIndex = i;
			}
		}
		TreeNode *root = new TreeNode(maxValue);

		vector<int> leftnums(nums.begin(), nums.begin() + maxIndex);
		vector<int> rightnums(nums.begin() + maxIndex + 1, nums.end());
		root->left = constructMaximumBinaryTree(leftnums);
		root->right = constructMaximumBinaryTree(rightnums);
		return root;
	}
};
class Solution2 {
 public:
	TreeNode *traversal(const vector<int> &nums, int leftIndex, int rightInndex) {
		if (leftIndex >= rightInndex) return nullptr;
		int maxIndex = 0;
		int maxValue = INT_MIN;
		for (int i = leftIndex; i < rightInndex; ++i) {
			if (nums[i] > maxValue) {
				maxValue = nums[i];
				maxIndex = i;
			}
		}
		TreeNode *root = new TreeNode(maxValue);

		int left_leftIndex = leftIndex;
		int left_rightIndex = maxIndex;
		int right_leftIndex = maxIndex + 1;
		int right_rightIndex = rightInndex;

		root->left = traversal(nums, left_leftIndex, left_rightIndex);
		root->right = traversal(nums, right_leftIndex, right_rightIndex);
		return root;

	}
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		//还是说要注意区间，我这里用的是左闭右开
		return traversal(nums, 0, nums.size());
	}
};