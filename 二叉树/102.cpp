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
    vector<vector<int> > levelOrder(TreeNode *root) {
      vector<vector<int> > res;
      queue<TreeNode *> que;
      if (root == nullptr)return res;
      que.push(root);
      while (!que.empty()) {
        int size = que.size();
        vector<int> temp;
        temp.clear();
        while (size--) {
          TreeNode *cur = que.front();
          que.pop();
          temp.push_back(cur->val);
          if (cur->left) que.push(cur->left);
          if (cur->right) que.push(cur->right);
        }
        res.emplace_back(temp);
      }
      return res;
    }
};
