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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)return res;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> temp;
      while (size--) {
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