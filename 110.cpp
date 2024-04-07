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
  int travel(TreeNode *node) {
    if (node == nullptr) return 0;
    int left = travel(node->left);
    int right = travel(node->right);
    if (left == -1) return -1;
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }
  bool isBalanced(TreeNode *root) {
    return (travel(root) == -1) ? false : true;
  }
};