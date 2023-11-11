// creat by ogier 2023/11/10
// 404.左子叶之和
#include <iostream>
#include <queue>
#include <stack>
#include <string>
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
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) return 0;  // 空节点，肯定无左节点
    // 叶子节点，一样没有左节点
    if (root->left == nullptr && root->right == nullptr) return 0;
    int leftValue = sumOfLeftLeaves(root->left);
    // 当前节点左节点存在，并且左节点是叶子节点，说明找到了
    if (root->left && !root->left->left && !root->left->right)
      leftValue = root->left->val;
    int rightValue = sumOfLeftLeaves(root->right);
    int res = leftValue + rightValue;
    return res;
  }
};