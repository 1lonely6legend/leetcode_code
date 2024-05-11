//
// Created by ogier on 2024/4/7.
//
#include <iostream>
#include <vector>
#include <string>
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
  void travel(TreeNode *node, vector<int> &res) {
    if (node == nullptr)
      return;
    travel(node->left, res);
    travel(node->right, res);
    res.push_back(node->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    travel(root, res);
    return res;
  }
};