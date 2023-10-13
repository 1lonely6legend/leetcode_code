//
// Created by ogier on 2023/10/12.
// 105.从前序与中序遍历序列构造二叉树

// 相比较于106,这次传入的参数更多,每次都需要数组的长度,区间更复杂一点

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.size() == 0 || preorder.size() == 0)
      return nullptr;

    // 参数坚持左闭右开的原则
    return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
  }

private:
  TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd,
                      vector<int> &preorder, int preorderBegin,
                      int preorderEnd) {
    if (preorderBegin == preorderEnd)
      return nullptr;

    int rootValue = preorder[preorderBegin]; // 注意用preorderBegin 不要用0
    TreeNode *root = new TreeNode(rootValue);

    if (preorderEnd - preorderBegin == 1)
      return root;

    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd;
         delimiterIndex++) {
      if (inorder[delimiterIndex] == rootValue)
        break;
    }
    // 切割中序数组
    // 中序左区间，左闭右开[leftInorderBegin, leftInorderEnd)
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = delimiterIndex;
    // 中序右区间，左闭右开[rightInorderBegin, rightInorderEnd)
    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;

    // 切割前序数组
    // 前序左区间，左闭右开[leftPreorderBegin, leftPreorderEnd)
    int leftPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd =
        preorderBegin + 1 + delimiterIndex -
        inorderBegin; // 终止位置是起始位置加上中序左区间的大小size
    // 前序右区间, 左闭右开[rightPreorderBegin, rightPreorderEnd)
    int rightPreorderBegin =
        preorderBegin + 1 + (delimiterIndex - inorderBegin);
    int rightPreorderEnd = preorderEnd;

    root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder,
                           leftPreorderBegin, leftPreorderEnd);
    root->right = traversal(inorder, rightInorderBegin, rightInorderEnd,
                            preorder, rightPreorderBegin, rightPreorderEnd);

    return root;
  }
};

int main() { return 0; }
