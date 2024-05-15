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
    int step;
    int res = 0;
    int travel(TreeNode *root, const int k) {
      if (root == nullptr) return 0;
      travel(root->left, k);
      step++;
      if (step == k)
        res = root->val;
      travel(root->right, k);
      return 0;
    }
    int kthSmallest(TreeNode *root, int k) {
      step = 0;
      travel(root, k);
      return res;
    }
};
