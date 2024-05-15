//
// Created by ogier on 24-5-15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <array>
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
    TreeNode *pre = nullptr;
    void travel(TreeNode *root, vector<TreeNode *> &l) {
      if (root == nullptr) return;
      l.push_back(root);
      travel(root->left, l);
      travel(root->right, l);
    }
    void flatten(TreeNode *root) {
      vector<TreeNode *> l;
      travel(root, l);
      int n = l.size();
      for (int i = 1; i < n; ++i) {
        TreeNode *pre = l.at(i - 1), *curr = l.at(i);
        pre->left = nullptr;
        pre->right = curr;
      }
    }
};
//该节点的左子树中最后一个被访问的节点是左子树中的最右边的节点，也是该节点的前驱节点。因此，问题转化成寻找当前节点的前驱节点。
class Solution2 {
  public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        auto next = curr->left;
        auto pre = next;
        while (pre->right) {
          pre = pre->right;
        }
        pre->right = curr->right;
        curr->left = nullptr;
        curr->right = next;
      }
      curr = curr->right;
    }
  }
};
