//
// Created by ogier on 2022/11/17.
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

string tree2str(TreeNode *root) {
  if (root == nullptr) {
    return "";
  }
  if (root->left == nullptr && root->right == nullptr) {
    return to_string(root->val);
  }
  if (root->right == nullptr) {
    return to_string(root->val) + "(" + tree2str(root->left) + ")";
  }
  return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  /*root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(7);*/

  string ans = tree2str(root);
  cout << ans;
  return 0;
}