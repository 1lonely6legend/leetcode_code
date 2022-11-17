//
// Created by ogier on 2022/11/16.
//
#include <cmath>
#include <vector>
using std::vector;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> answer;
int base, count, maxCount;

void update(int x) {
  if (x == base) {
    ++count;
  } else {
    count = 1;
    base = x;
  }
  if (count == maxCount) {
    answer.push_back(base);
  }
  if (count > maxCount) {
    maxCount = count;
    answer = vector<int>{base};
  }
}

void dfs(TreeNode *o) {
  if (!o) {
    return;
  }
  dfs(o->left);
  update(o->val);
  dfs(o->right);
}

vector<int> findMode(TreeNode *root) {
  dfs(root);
  return answer;
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(7);

  vector<int> ans = findMode(root);

  return 0;
}