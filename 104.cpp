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
  int maxDepth(TreeNode *root) {
    int res = 0;
    if (root == nullptr) return 0;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      res++;
      int size = que.size();
      while (size--) {
        TreeNode *cur = que.front();
        que.pop();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
    }
    return res;
  }
};