//
// Created by ogier on 2022/11/10.
//
#include <vector>
#include <string>
using std::vector;
using std::string;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void construct_paths(TreeNode *root, string path, vector<string> &paths) {
  if (root != nullptr) {
    path += std::to_string(root->val);//to_string函数,将数字常量转化为字符串,利用string的+运算符
    if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
      paths.push_back(path);                              // 把路径加入到答案中
    } else {
      path += "->";  // 当前节点不是叶子节点，继续递归遍历
      construct_paths(root->left, path, paths);
      construct_paths(root->right, path, paths);
    }
  }
}

vector<string> binaryTreePaths(TreeNode *root) {
  vector<string> paths;
  construct_paths(root, "", paths);
  return paths;
}
