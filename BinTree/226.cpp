//
// Created by ogier on 2022/11/10.
//226. 翻转二叉树
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//我的做法:递归
/*
TreeNode *invertTree(TreeNode *root) {
  if(!root) return root;
  if (root->left == nullptr && root->right == nullptr)
    return root;
  TreeNode *temp;
  temp = root->left;
  root->left = root->right;
  root->right = temp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}
*/

//bfs
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    queue < TreeNode * > que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = que.front();
        que.pop();
        TreeNode *temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
    }
    return root;
  }
};


//leetcode官解递归
/*
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};*/
