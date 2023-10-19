//
// Created by ogier on 2023/10/19.
// 108.将有序数组转换为二叉搜索树

#include <iostream>
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
	TreeNode(int x, TreeNode *left, TreeNode *right)
			: val(x), left(left), right(right) {}
};

/*class Solution {
 public:
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		int size = nums.size();
		if (size == 0) return nullptr;
		int midIndex;
		if (size % 2) {
			midIndex = (size - 1) / 2;
		} else {
			midIndex = size / 2;
		}
		TreeNode *root = new TreeNode(nums[midIndex]);
		vector<int> leftvec(nums.begin(), nums.begin() + midIndex);
		vector<int> rightvec(nums.begin() + midIndex + 1, nums.end());
		root->left = sortedArrayToBST(leftvec);
		root->right = sortedArrayToBST(rightvec);
		return root;
	}
};*/

class Solution {
 private:
	TreeNode* traversal(vector<int>& nums, int left, int right) {
		if (left > right) return nullptr;
		int mid = left + ((right - left) / 2);
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = traversal(nums, left, mid - 1);
		root->right = traversal(nums, mid + 1, right);
		return root;
	}
 public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = traversal(nums, 0, nums.size() - 1);
		return root;
	}
};


