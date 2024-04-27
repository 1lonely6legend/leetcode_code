//
// Created by ogier on 2023/11/13.
// 验证二叉搜索树
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
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
class Solution {
public:
  TreeNode *pre = NULL; // 用来记录前一个节点
  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return true;
    bool left = isValidBST(root->left);

    if (pre != NULL && pre->val >= root->val)
      return false;
    pre = root; // 记录前一个节点

    bool right = isValidBST(root->right);
    return left && right;
  }
};

int main() {
  TreeNode *root = new TreeNode(0);
  Solution S;
  auto a = S.isValidBST(root);
	return 0;
}