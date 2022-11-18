//
// Created by ogier on 2022/11/18.
//
#include <string>
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr) return t2; // 如果t1为空，合并之后就应该是t2
  if (t2 == nullptr) return t1; // 如果t2为空，合并之后就应该是t1
  // 修改了t1的数值和结构
  t1->val += t2->val;                             // 中
  t1->left = mergeTrees(t1->left, t2->left);      // 左
  t1->right = mergeTrees(t1->right, t2->right);   // 右
  return t1;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(5);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  /*root1->right->left = new TreeNode(7);
  root1->right->right = new TreeNode(7);*/

  TreeNode *root2 = new TreeNode(7);
  root2->left = new TreeNode(3);
  root2->right = new TreeNode(9);
  TreeNode *ans = mergeTrees(root1, root2);

  return 0;
}