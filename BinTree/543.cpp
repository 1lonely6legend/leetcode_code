//
// Created by ogier on 2022/11/14.
//

#include <cmath>
using std::max;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//直接官解,做了半天没想出来


int ans;//需要传递引用的时候其实可以建立一个全局变量
int depth(TreeNode *rt) {
  if (rt == nullptr) {
    return 0; // 访问到空节点了，返回0
  }
  int L = depth(rt->left); // 左儿子为根的子树的深度
  int R = depth(rt->right); // 右儿子为根的子树的深度
  ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
  return max(L, R) + 1; // 返回该节点为根的子树的深度
}

int diameterOfBinaryTree(TreeNode *root) {
  ans = 1;
  depth(root);
  return ans - 1;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int ans = diameterOfBinaryTree(root);

  return 0;
}