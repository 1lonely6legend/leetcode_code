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
    bool travel(TreeNode *left, TreeNode *right) {
      if (left == nullptr && right == nullptr)
        return true;
      else if (left == nullptr && right != nullptr)
        return false;
      else if (left != nullptr && right == nullptr)
        return false;
      else if (left->val != right->val)return false;
      return travel(left->left, right->right) && travel(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
      return travel(root->left, root->right);
    }
};
