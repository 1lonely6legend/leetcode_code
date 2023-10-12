//
// Created by ogier on 2023/10/11.
// 112.路经总和

// #define null -1;

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

TreeNode *construct_binary_tree(const vector<int> &vec) {
  vector<TreeNode *> vecTree(vec.size(), nullptr);
  TreeNode *root = nullptr;
  for (int i = 0; i < vec.size(); ++i) {
    // 对原始int数组进行遍历,在node数组中生成对应的节点
    TreeNode *node = nullptr;
    if (vec[i] != -1)
      node = new TreeNode(vec[i]); // use -1 sign null
    vecTree[i] = node;
    if (i == 0)
      root = node;
  }
  for (int i = 0; i * 2 + 1 < vec.size(); ++i) {
    // 通过数组下标之间的关系,将各个节点链接,形成二叉树
    if (vecTree[i] != nullptr) {
      vecTree[i]->left = vecTree[i * 2 + 1];
      if (i * 2 + 2 < vec.size()) // 这里需要考虑是否存在右节点
        vecTree[i]->right = vecTree[i * 2 + 2];
    }
  }
  return root;
}

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
      return false;
    return traversal(root, targetSum - root->val);
    // 关键点就是在函数入参时减去val值
  }

private:
  bool traversal(TreeNode *cur, int count) {
    if (!cur->left && !cur->right && count == 0)
      // 叶子节点并且计数为0
      return true;
    if (!cur->left && !cur->right)
      return false;
    // 下面为不是叶子节点时的处理
    if (cur->left) {
      count -= cur->left->val;
      if (traversal(cur->left, count))
        // 说明在这个分支上,递归到最后有恰好为0的结果
        return true;
      count += cur->left->val; // 如没有返回0,那就回溯,把count再加回去
    }
    if (cur->right) {
      count -= cur->right->val;
      if (traversal(cur->right, count))
        return true;
      count += cur->right->val;
    }
    return false;
  }
};

int main() {
  vector<int> raw = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
  TreeNode *root = construct_binary_tree(raw);
  Solution s;
  bool res = s.hasPathSum(root, 22);
  cout << res;
  return 0;
}
