//
// Created by ogier on 2022/11/17.
//
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool ans;//首先设置全局变量

bool duibi(TreeNode *root, TreeNode *subroot) {
  //两棵树是否一样的对比,使用了第100道的代码
  if (root == nullptr && subroot == nullptr)
    return true;
  if (root == nullptr || subroot == nullptr)
    return false;
  if (root->val != subroot->val)
    return false;
  return duibi(root->left, subroot->left) && duibi(root->right, subroot->right);
}
void dfs(TreeNode *root, TreeNode *subroot) {
  //这个就是把root树按照dfs顺序进行搜索,
  // 如果遇到有节点和subroot的根节点一样,那我就从这开始对比一下
  if (!root) return;
  if (root->val == subroot->val)
    //感觉我这个写的蛮妙的
    //如果之前的ans已经是一了,那么之后对比是否一样不会影响最后的true
    ans = duibi(root, subroot) || ans;
  dfs(root->left, subroot);
  dfs(root->right, subroot);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  dfs(root,subRoot);//进行dfs
  return ans;
}

int main() {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(9);
//  root->left->left = new TreeNode(1);
//  root->left->right = new TreeNode(5);
  /*root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(7);*/

  TreeNode *root1 = new TreeNode(7);
  root1->left = new TreeNode(3);
  root1->right = new TreeNode(9);

  int ans = isSubtree(root, root1);
  cout << ans;
  return 0;
}