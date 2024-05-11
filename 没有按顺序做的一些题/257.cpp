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
  void travel(TreeNode *node, vector<string> &res, vector<int> &path) {
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      string spath;
      for (int i = 0; i < path.size() - 1; ++i) {
        spath += to_string(path[i]);
        spath += "->";
      }
      spath += to_string(*(path.end() - 1));
      res.push_back(spath);
      return;
    }
    if (node->left) {
      travel(node->left, res, path);
      path.pop_back();
    }
    if (node->right) {
      travel(node->right, res, path);
      path.pop_back();
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    if (root == nullptr)
      return res;
    travel(root, res, path);
    return res;
  }
};