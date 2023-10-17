//
// Created by ogier on 2023/10/17.
// 98.验证二叉搜索树
//递归遍历中序,看数字是不是越来越大
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
	TreeNode *pre = nullptr;
	bool isValidBST(TreeNode *root) {
		if (root == nullptr) return true;
		bool left = isValidBST(root->left);
		if (pre != nullptr && pre->val >= root->val)
			return false;
		pre = root;

		bool right = isValidBST(root->right);
		return left && right;
	}
};

int main() {

	return 0;
}