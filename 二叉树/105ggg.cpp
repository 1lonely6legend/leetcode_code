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
  private:
    TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &preorder, int preorderBegin, int preorderEnd) {
      if (preorderBegin > preorderEnd) return NULL;

      int rootValue = preorder[preorderBegin]; // 注意用preorderBegin 不要用0
      TreeNode *root = new TreeNode(rootValue);

      if (preorderEnd == preorderBegin ) return root;

      int delimiterIndex;
      for (delimiterIndex = inorderBegin; delimiterIndex <= inorderEnd; delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
      }
      // 切割中序数组
      int leftInorderBegin = inorderBegin;
      int leftInorderEnd = delimiterIndex - 1;
      int rightInorderBegin = delimiterIndex + 1;
      int rightInorderEnd = inorderEnd;

      // 切割前序数组
      int leftPreorderBegin = preorderBegin + 1;
      int leftPreorderEnd = preorderBegin + delimiterIndex - inorderBegin; // 终止位置是起始位置加上中序左区间的大小size

      int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
      int rightPreorderEnd = preorderEnd;

      root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
      root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

      return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      if (inorder.size() == 0 || preorder.size() == 0) return NULL;

      // 参数坚持左闭右闭的原则
      return traversal(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
    }
};
