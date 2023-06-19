//
// Created by ogier on 2023/6/16.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//前序遍历
class PreorderTraversal {
 public:
  vector<int> preorder_traversal(TreeNode *root) {
    vector<int> vec;
    traversal(root, vec);
    return vec;
  }
 private:
  void traversal(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) return;
    vec.push_back(cur->val);
    traversal(cur->left, vec);
    traversal(cur->right, vec);
  }
};
//中序遍历
class InorderTraversal {
 public:
  vector<int> inorder_traversal(TreeNode *root) {
    vector<int> vec;
    traversal(root, vec);
    return vec;
  }
 private:
  void traversal(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) return;
    traversal(cur->left, vec);
    vec.push_back(cur->val);
    traversal(cur->right, vec);
  }
};
//后序遍历
class PostorderTraversal {
 public:
  vector<int> postorder_traversal(TreeNode *root) {
    vector<int> vec;
    traversal(root, vec);
    return vec;
  }
 private:
  void traversal(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) return;
    traversal(cur->left, vec);
    traversal(cur->right, vec);
    vec.push_back(cur->val);
  }
};