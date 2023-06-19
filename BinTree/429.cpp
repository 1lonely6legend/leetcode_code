//
// Created by ogier on 2023/6/19.
// 429. N 叉树的层序遍历
#include <queue>
#include <vector>
using std::queue;
using std::vector;
// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) { val = _val; }
  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    queue<Node *> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
      vector<int> temp;
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        Node *cur = que.front();
        que.pop();
        temp.push_back(cur->val);
        for (auto iter : cur->children)
          if (iter) que.push(iter);
      }
      res.push_back(temp);
    }
    return res;
  }
};