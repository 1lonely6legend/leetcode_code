//
// Created by ogier on 2023/10/11.
// 参考
// https://programmercarl.com/%E5%89%8D%E5%BA%8F/ACM%E6%A8%A1%E5%BC%8F%E5%A6%82%E4%BD%95%E6%9E%84%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.html#java

// ACM格式练习网站,https://kamacoder.com/

// 通过数组可以直接确定二叉树,直接通过数组下标进行构建,当前节点下标i,其左右孩子的下表为2i+1和2i+2

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *construct_binary_tree(const vector<int> &vec) {
  vector<TreeNode *> vecTree(vec.size(), nullptr);//size个,使用每个元素初始化为空指针
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
// 层序打印打印二叉树
void print_binary_tree(TreeNode* root) {
  queue<TreeNode*> que;
  if (root != NULL) que.push(root);
  vector<vector<int>> result;
  while (!que.empty()) {
    int size = que.size();
    vector<int> vec;
    for (int i = 0; i < size; i++) {
      TreeNode* node = que.front();
      que.pop();
      if (node != NULL) {
        vec.push_back(node->val);
        que.push(node->left);
        que.push(node->right);
      }
      // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
      else vec.push_back(-1);
    }
    result.push_back(vec);
  }
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // 注意本代码没有考虑输入异常数据的情况
  // 用 -1 来表示null
  vector<int> vec = {5,4,8,11,3,13,4,7,2,-1,-1,5,1,5,1};
  TreeNode* root = construct_binary_tree(vec);
  print_binary_tree(root);
}
