//
// Created by ogier on 2023/6/19.
//199. 二叉树的右视图
#include <queue>
#include <vector>
using std::queue;
using std::vector;
//Definition for a binary tree node.
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      TreeNode *target = nullptr;
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = que.front();
        target = cur;
        que.pop();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
      res.push_back(target->val);
    }
    return res;
  }
};