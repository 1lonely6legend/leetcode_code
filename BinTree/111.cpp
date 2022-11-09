//
// Created by ogier on 2022/11/9.
//
#include <cmath>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void TravPre(TreeNode *root, int &ans, int &temp) {
  temp++;
  if (root->left == nullptr && root->right == nullptr) {//当访问到空节点时
    ans = (ans <= temp) ? ans : temp;
    temp--;
    return;
  }
  if (root->left)
    TravPre(root->left, ans, temp);
  if (root->right)
    TravPre(root->right, ans, temp);
  temp--;//应该放到函数的最后，这样才是每次回溯节点的地方，而不是放到第17行的return后面
}
int minDepth(TreeNode *root) {
  int ans = 1000000;
  int temp = 0;
  if (root == nullptr)
    return 0;
  else
    TravPre(root, ans, temp);
  return ans;
}
