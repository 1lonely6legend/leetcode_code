//
// Created by ogier on 2023/10/16.
// 654.最大二叉树

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

TreeNode *construct_binary_tree(const vector<int> &vec) {
	vector<TreeNode *> vecTree(vec.size(), nullptr);//size个,使用每个元素初始化为空指针
	TreeNode *root = nullptr;
	for (int i = 0; i < vec.size(); ++i) {
		// 对原始int数组进行遍历,在node数组中生成对应的节点
		TreeNode *node = nullptr;
		if (vec[i] != -1)
			node = new TreeNode(vec[i]); // use -1 sign null
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for (int i = 0; i * 2 + 1 < vec.size(); ++i) {
		// 通过数组下标之间的关系,将各个节点链接,形成二叉树
		if (vecTree[i] != nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			if (i * 2 + 2 < vec.size()) // 这里需要考虑是否存在右节点
				vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}

class Solution {
 public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		return construct(nums);
	}
 private:
	/*
	 * @brief 递归构造最大二叉树
	 * @details 占用的空间过大,每次递归都要重新分割数组,优化可以传入数组下标,一个意思占用空间更少.
	 */
	TreeNode *construct(vector<int> nums) {
		if (nums.empty()) return nullptr;
		if (nums.size() == 1) return new TreeNode(nums[0]);
		int maxindex = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[maxindex] <= nums[i]) maxindex = i;
		}
		TreeNode *root = new TreeNode(nums[maxindex]);
		vector<int> leftnums(nums.begin(), nums.begin() + maxindex);
		vector<int> rightnums(nums.begin() + maxindex + 1, nums.end());
		root->left = construct(leftnums);
		root->right = construct(rightnums);
		return root;
	}
};

int main() {
	vector<int> test = {3, 2, 1, 6, 0, 5};
	Solution S;
	TreeNode *res = nullptr;
	res = S.constructMaximumBinaryTree(test);
	return 0;
}
