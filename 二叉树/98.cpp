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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root) {
      if (root == nullptr) return true;
      bool L = isValidBST(root->left);
      if (pre != nullptr && pre->val >= root->val)
        return false;
      pre = root;
      bool R = isValidBST(root->right);
      return L && R;
    }
};
