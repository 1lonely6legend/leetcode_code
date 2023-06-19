//
// Created by ogier on 2023/6/19.
//103. 二叉树的锯齿形层序遍历
#include <algorithm>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    bool left2right = true;
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
      if (left2right) {
        res.push_back(temp);
        left2right = false;
      } else {
        std::reverse(temp.begin(), temp.end());
        res.push_back(temp);
        left2right = true;
      }
    }
    return res;
  }
};