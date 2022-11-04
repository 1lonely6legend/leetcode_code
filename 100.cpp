//
// Created by ogier on 2022/11/4.
//
#include <queue>
using std::queue;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//使用深度优先搜索，前序搜索二叉树是DFS的一种情况
//让两棵树同时DFS，考虑几种情况，每次搜索都对比一下val
bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr)//最优先的情况，两者都遍历结束，如果前面没问题的话，说明两棵树相同。
    return true;
  if (p == nullptr || q == nullptr)//如果其中国有一颗先到头，那肯定是对不上，直接false
    return false;
  if (p->val != q->val)//如果目前这次遍历两个节点都存在，那么就对比一下储存的val数据，不同的话就直接false
    return false;
  //关键点
  //首先如果能走到这一步，说明当前节点及其事之前是一致的，
  //因此开始分别对节点的左右数进行对比查找遍历。
  //tnnd，为啥这个return && 我怎么想不到记住记住
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

