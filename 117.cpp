//
// Created by ogier on 2023/6/19.
// 117. 填充每个节点的下一个右侧节点指针 II
#include <queue>
#include <vector>
using std::queue;
using std::vector;
// Definition for a Node.
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
  vector<int> level;
  queue<Node *> que;
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    int size = que.size();
    Node *pre = nullptr;
    for (int i = 0; i < size; ++i) {
      Node *cur = que.front();
      que.pop();
      if (pre) pre->next = cur;
      pre = cur;
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    }
    pre->next = nullptr;
  }
  return root;
}
int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(5);
  root->right->left->left = nullptr;
  root->right->left->right = new Node(7);
  Node *res = connect(root);

  return 0;
}