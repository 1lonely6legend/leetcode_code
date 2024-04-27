//
// Created by ogier on 2023/11/13.
// 最大二叉树
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *traversal(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;
    int max = INT_MIN, max_index = left;
    for (int i = left; i <= right; ++i) {
      if (nums[i] > max) {
        max = nums[i];
        max_index = i;
      }
    }
    TreeNode *root = new TreeNode(max);
    if (left == right)
      return root;
    root->left = traversal(nums, left, max_index - 1);
    root->right = traversal(nums, max_index + 1, right);
    return root;
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.size() == 0)
      return nullptr;
    return traversal(nums, 0, nums.size() - 1);
  }
};
