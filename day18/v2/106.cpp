//
// Created by ogier on 2023/11/12.
// 106.从中序和后序遍历序列构造二叉树
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {
  }
};

class Solution {
  public:
    TreeNode *traversal(vector<int> &inorder,
                        vector<int> &postorder,
                        int inorder_start,
                        int inorder_end,
                        int postorder_start,
                        int postorder_end) {
      if (postorder_start == postorder_end) return nullptr;

      int root_value = postorder[postorder_end - 1];
      TreeNode *root = new TreeNode(root_value);
      if (postorder_end - postorder_start == 1) return root;

      int split_index;
      for (split_index = inorder_start; split_index < inorder_end; ++split_index) {
        if (inorder[split_index] == root_value) break;
      }

      int leftInorderBegin = inorder_start;
      int leftInorderEnd = split_index;
      int rightInorderBegin = split_index + 1;
      int rightInorderEnd = inorder_end;

      int leftPostorderBegin = postorder_start;
      int leftPostorderEnd = postorder_start + split_index - inorder_start;
      int rightPostorderBegin = postorder_start + split_index - inorder_start;
      int rightPostorderEnd = postorder_end - 1;

      root->left = traversal(inorder,
                             postorder,
                             leftInorderBegin,
                             leftInorderEnd,
                             leftPostorderBegin,
                             leftPostorderEnd);
      root->right = traversal(inorder,
                              postorder,
                              rightInorderBegin,
                              rightInorderEnd,
                              rightPostorderBegin,
                              rightPostorderEnd);

      return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      if (inorder.size() == 0)
        return nullptr;
      return traversal(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
