//
// Created by ogier on 2023/6/19.
// 102. 二叉树的层序遍历
#include <iostream>
#include <queue>
#include <vector>
using std::queue;
using std::vector;
// Definition for a binary tree node.
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> temp;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = que.front();
        que.pop();
        temp.push_back(cur->val);
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
      res.push_back(temp);
    }
    return res;
  }
};



