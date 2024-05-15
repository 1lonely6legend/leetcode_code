//
// Created by ogier on 24-5-15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
      if (root == nullptr || root == p || root == q)
        return root; //如果root为空或者root等于p或者root等于q，那么返回root
      TreeNode *L = lowestCommonAncestor(root->left, p, q); //递归左子树
      TreeNode *R = lowestCommonAncestor(root->right, p, q); //递归右子树
      if (L != nullptr && R != nullptr)
        //两边都找到了，说明root就是最近公共祖先
        return root;
      if (L == nullptr && R != nullptr)
        //左边没找到，右边找到了，说明最近公共祖先在右边
        return R;
      else if (L != nullptr && R == nullptr)
      //右边没找到，左边找到了，说明最近公共祖先在左边
        return L;
      else {
        //两边都没找到，返回空指针
        return nullptr;
      }
    }
};
