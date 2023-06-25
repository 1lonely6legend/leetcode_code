//
// Created by ogier on 2023/6/25.
// 222. 完全二叉树的节点个数
#include <vector>
#include <queue>
using std::vector;
using std::queue;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int countNodes(TreeNode *root) {
    queue<TreeNode *> que;
    int res = 0;
    bool bottom_level = false;
    if (root != nullptr) {
      que.push(root);
    }
    while (!que.empty()) {
      int size = que.size();
      res += size;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = que.front();
        que.pop();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
      }
    }
    return res;
  }
};

//官解:二分查找加位运算

bool exists(TreeNode *root, int level, int k) {
  //根据二叉树的索引,判断那个节点是否存在
  int bits = 1 << (level - 1);
  TreeNode *node = root;
  while (node != nullptr && bits > 0) {
    if (!(bits & k)) {
      node = node->left;
    } else {
      node = node->right;
    }
    bits >>= 1;
  }
  return node != nullptr;
}
int countNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int level = 0;
  TreeNode *node = root;
  while (node->left != nullptr) {//找到最底层最左节点,获得层数
    level++;
    node = node->left;
  }
  //通过位运算获得最底层这一层节点,索引的最大值和最小值
  int low = 1 << level, high = (1 << (1 << level)) - 1;
  while (low < high) {//进行二分查找
    int mid = (high - low + 1) / 2 + low;
    if (exists(root, level, mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  return low;
}















