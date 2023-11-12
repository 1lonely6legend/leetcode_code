//
// Created by ogier on 2023/11/12.
// 105.从前序与中序遍历序列构造二叉树
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (inorder.size() == 0 || preorder.size() == 0)
			return nullptr;

		// 参数坚持左闭右开的原则
		return traversal(inorder, preorder);
	}

 private:
	TreeNode *traversal(vector<int> &inorder, vector<int> &preorder) {
		if (preorder.size() == 0)
			return nullptr;

		int rootValue = preorder[0]; // 注意用preorderBegin 不要用0
		TreeNode *root = new TreeNode(rootValue);

		if (preorder.size() == 1)
			return root;

		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size();
				 delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue)
				break;
		}
		// 切割中序数组
		// 左闭右开区间：[0, delimiterIndex)
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
		// [delimiterIndex + 1, end)
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

		// preorder 舍弃末尾元素
		preorder.erase(preorder.begin());

		// 切割后序数组
		// 依然左闭右开，注意这里使用了左中序数组大小作为切割点
		// [0, leftInorder.size)
		vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
		// [leftInorder.size(), end)
		vector<int> rightPretorder(preorder.begin() + leftInorder.size(), preorder.end());

		root->left = traversal(leftInorder, leftPreorder);
		root->right = traversal(rightInorder, rightPretorder);

		return root;
	}
};