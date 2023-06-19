//
// Created by ogier on 2023/6/19.
// 107. 二叉树的层序遍历 II
#include<vector>
#include<queue>
#include <algorithm>
using std::vector;
using std::queue;
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> temp;
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = que.front();
        que.pop();
        temp.push_back(cur->val);
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
      res.push_back(temp);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
