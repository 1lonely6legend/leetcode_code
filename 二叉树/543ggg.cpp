//
// Created by ogier on 24-5-15.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
  }
};
class Solution {
  public:
    int res = 1;
    int depth(TreeNode *root) {
      if (root == nullptr)
        return 0;
      int R = depth(root->right);
      int L = depth(root->left);
      res = max(res, R + L + 1);
      return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root) {
      res = 1;
      depth(root);
      return res - 1;
    }
};
