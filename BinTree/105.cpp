//
// Created by ogier on 2023/10/12.
// 105.从前序与中序遍历序列构造二叉树
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
  }
};

int main(){

  return 0;
}
