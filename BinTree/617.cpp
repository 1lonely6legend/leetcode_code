//
// Created by ogier on 2023/10/16.
//
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
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;
		queue<TreeNode *> que;
		que.push(root1);
		que.push(root2);
		while (que.empty()) {
			TreeNode *node1 = que.front();
			que.pop();
			TreeNode *node2 = que.front();
			que.pop();
			node1->val += node2->val;
			if (node1->left != nullptr && node2->left != nullptr) {
				que.push(node1->left);
				que.push(node2->left);
			}
			if (node1->right != nullptr && node2->right != nullptr) {
				que.push(node1->right);
				que.push(node2->right);
			}

			// 当t1的左节点 为空 t2左节点不为空，就赋值过去
			if (node1->left == nullptr && node2->left != nullptr) {
				node1->left = node2->left;
			}
			// 当t1的右节点 为空 t2右节点不为空，就赋值过去
			if (node1->right == nullptr && node2->right != nullptr) {
				node1->right = node2->right;
			}
		}
		return root1;
	}
};

int main() {
	TreeNode *tree1 = construct_binary_tree({1, 3, 2, 5});
	TreeNode *tree2 = construct_binary_tree({2, 1, 3, -1, 4, -1, 7});
	Solution S;
	TreeNode *res = S.mergeTrees(tree1, tree2);
	return 0;
}