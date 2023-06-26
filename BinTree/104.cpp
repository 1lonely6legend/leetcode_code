//
// Created by ogier on 2022/11/7.
//
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//DFS？Travpre！

////////////////
//关键点：想清楚回溯是到底在哪把临时变量减一
//////////////////
void TravPre(TreeNode *root, int &ans, int &temp) {
  if (!root) {//当访问到空节点时
    ans = (ans >= temp) ? ans : temp;
    return;
  } else {
    temp++;
    //ans = (ans >= temp) ? ans : temp;
  }
  TravPre(root->left, ans, temp);
  TravPre(root->right, ans, temp);
  temp--;//应该放到函数的最后，这样才是每次回溯节点的地方，而不是放到第23行的return后面
}
int maxDepth(TreeNode *root) {
  int ans = 0;
  int temp = 0;
  TravPre(root, ans, temp);
  return ans;
}

int main() {
//  TreeNode *root = nullptr;
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = nullptr;
  root->right->left->left = nullptr;
  root->right->left->right = nullptr;
  int ans = maxDepth(root);

  return 0;
}

//
class Soultion {
 public:
  int result;
  void getDepth(TreeNode *node, int depth) {
    result = depth > result ? depth : result;
    if (node->left == nullptr && node->right == nullptr)return;
    if (node->left) {
      depth++;
      getDepth(node->left, depth);
      depth--;
    }
    if (node->right) {
      depth++;
      getDepth(node->right, depth);
      depth--;
    }
    return;
  }
  int maxDepth(TreeNode *root) {
    result = 0;
    if (root == nullptr) return result;
    getDepth(root, 1);
    return result;
  }
};


