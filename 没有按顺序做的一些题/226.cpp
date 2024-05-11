
//
// Created by ogier on 2024/4/7.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
  TreeNode *travel(TreeNode *node) {
    if (node == nullptr)
      return nullptr;
    swap(node->left, node->right);
    travel(node->left);
    travel(node->right);
    return node;
  }
  TreeNode *invertTree(TreeNode *root) {
    return travel(root);
  }
};