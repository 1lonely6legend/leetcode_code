//
// Created by ogier on 2023/10/12.
// 113.路径总和II
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *construct_binary_tree(const vector<int> &vec) {
  vector<TreeNode *> vecTree(vec.size(), nullptr);
  TreeNode *root = nullptr;
  for (int i = 0; i < vec.size(); ++i) {
    TreeNode *node = nullptr;
    if (vec[i] != -1)
      node = new TreeNode(vec[i]);
    vecTree[i] = node;
    if (i == 0)
      root = node;
  }
  for (int i = 0; i * 2 + 1 < vec.size(); ++i) {
    // 注意区间,当i*1+1>size的时候,节点就是叶子节点了,不用在考虑
    if (vecTree[i] != nullptr) {
      vecTree[i]->left = vecTree[i * 2 + 1];
      if (i * 2 + 2 < vec.size())
        vecTree[i]->right = vecTree[i * 2 + 2];
    }
  }
  return root;
}

class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
      return {};
    vector<int> temp;
    temp.push_back(root->val);
    traversal(root, targetSum - root->val, temp);
    return res;
  }

private:
  void traversal(TreeNode *cur, int count, vector<int> temp) {
    if (!cur->left && !cur->right) {
      if (count == 0)
        res.push_back(temp);
    }
    if (cur->left) {
      temp.push_back(cur->left->val);
      count -= cur->left->val;
      traversal(cur->left, count, temp);
      temp.pop_back();
      count += cur->left->val;
    }
    if (cur->right) {
      temp.push_back(cur->right->val);
      count -= cur->right->val;
      traversal(cur->right, count, temp);
      temp.pop_back();
      count += cur->right->val;
    }
  }
};
int main() {
  vector<int> raw = {5,4,8,11,3,13,4,7,2,-1,-1,5,1,5,1};
  //  vector<int> raw = {1};
  TreeNode *root = construct_binary_tree(raw);
  Solution s;
  auto res = s.pathSum(root, 22);
  for (auto iter = res.begin(); iter != res.end(); ++iter) {
    for (auto it = iter->begin(); it != iter->end(); ++it) {
      cout << *it << " ";
    }
    cout << '\n';
  }
  return 0;
}
