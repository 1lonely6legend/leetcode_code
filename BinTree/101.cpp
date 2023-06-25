//
// Created by ogier on 2022/11/4.
// 101. 对称二叉树
#include<queue>
using std::queue;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode官解
/*bool duibi(TreeNode *pl, TreeNode *pr) {
  if (pl == nullptr && pr == nullptr)
    return true;
  if (pl == nullptr || pr == nullptr)
    return false;
  if (pl->val != pr->val)
    return false;
  return duibi(pl->left, pr->right) && duibi(pl->right, pr->left);
}

bool isSymmetric(TreeNode *root) {
  //TreeNode *pl = root, *pr = root;，不需要直接传递 root root
  return duibi(root, root);
}*/
// 递归
/*bool compare(TreeNode *left, TreeNode *right) {
  //首先判断两个节点是否都存在
  if (left == nullptr && right != nullptr) return false;
  else if (left != nullptr && right == nullptr) return false;
  else if (left == nullptr && right == nullptr) return true;
    //如果两个节点都存在的话，接下来判断，节点的val是否相等
  else if (left->val != right->val) return false;

  bool outside = compare(left->left, right->right);
  bool inside = compare(left->right, right->left);
  bool is_same = outside && inside;
  return is_same;
}
bool isSymmetric(TreeNode *root) {
  if (root == nullptr) return true;
  return compare(root->left, root->right);
}*/

//迭代
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return false;
    queue<TreeNode *> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
      TreeNode *leftnode = que.front();
      que.pop();
      TreeNode *rightnode = que.front();
      que.pop();
      if (rightnode == nullptr && leftnode == nullptr)
        continue;
      if (!leftnode || !rightnode || leftnode->val != rightnode->val) {
        return false;
      }
      que.push(leftnode->left);
      que.push(rightnode->right);
      que.push(leftnode->right);
      que.push(rightnode->left);
    }
    return true;
  }
};



