//
// Created by ogier on 2023/11/15.
// 450.删除二叉搜索树中的节点
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
	TreeNode *deleteNode(TreeNode *root, int key) {
		if (root == nullptr) return root;
		int flag = 1;
		TreeNode *dummy = new TreeNode(-1);
		dummy->right = root;
		TreeNode *pre = dummy;
		TreeNode *cur = root;
		while (cur != nullptr) {
			if (cur->val == key) break;
			if (cur->val > key) {
				pre = cur;
				cur = cur->left;
				flag = -1;
			} else {
				pre = cur;
				cur = cur->right;
				flag = 1;
			}
		}//找到val的节点,以及其前驱节点pre
		if (cur == nullptr) {
			return dummy->right;
		} else if (cur->left == nullptr) {
			//删除的节点左子树空
			if (flag == 1) {
				pre->right = cur->right;
				delete cur;
			} else {
				pre->left = cur->right;
				delete cur;
			}
		} else if (cur->right == nullptr) {
			//删除的节点右子树空
			if (flag == 1) {
				pre->right = cur->left;
				delete cur;
			} else {
				pre->left = cur->left;
				delete cur;
			}
		} else {
			//需要删除的节点,左右子树均存在
			TreeNode *temp = cur->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			temp->left = cur->left;
			if (flag == 1) {
				pre->right = cur->right;
				delete cur;
			} else {
				pre->left = cur->right;
				delete cur;
			}
		}
		return dummy->right;
	}
};

int main() {
	TreeNode* root = new TreeNode(50);
	root->right = new TreeNode(70);
	root->left = new TreeNode(30);
	root->left->right = new TreeNode(40);
	root->right->left = new TreeNode(60);
	root->right->right = new TreeNode(80);
	Solution S;
	S.deleteNode(root,50);
	return 0;
}