//
// Created by ogier on 2022/11/10.
//
#include<vector>
#include<stack>
using std::vector;
using std::stack;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//迭代版本
vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr)
    return ans;

  stack<TreeNode *> head;//怎么去维护这个相当于递归调用时的各个root节点的栈呢?????
  TreeNode *prev = nullptr;
  while (root != nullptr || head.empty()) {//关键点,避免重复遍历
    while (root != nullptr) {//将最左边的节点压入栈中
      head.emplace(root);
      root = root->left;
    }
    root = head.top();
    head.pop();//取出栈顶元素
    if (root->right == nullptr || root->right == prev) {//判断右孩子是否存在或者刚刚回溯
      ans.emplace_back(root->val);
      prev = root;
      root = nullptr;
    } else {
      head.emplace(root);
      root = root->right;
    }
  }
  return ans;
}

////后续便利,注意一下传入引用就差不多了
//void travpre(TreeNode *root, vector<int> &ans) {
//  if (!root)
//    return;
//  travpre(root->left, ans);
//  travpre(root->right, ans);
//  ans.push_back(root->val);
//}
//
//vector<int> postorderTraversal(TreeNode *root) {
//  vector<int> ans;
//  travpre(root, ans);
//  return ans;
//}

