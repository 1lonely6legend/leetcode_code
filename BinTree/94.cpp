//
// Created by ogier on 2022/11/3.
//
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

void travIn(TreeNode *root, vector<int> &ans) {//要传入&ans而不是ans，本题中ans一直是按着数组传递，没有用指针
  if (root == nullptr)
    return;
  travIn(root->left, ans);
  ans.push_back(root->val);
  travIn(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;
  travIn(root, ans);
  return ans;
}

/*官方答案
void inorder(TreeNode* root, vector<int>& res) {
  if (!root) {
    return;
  }
  inorder(root->left, res);
  res.push_back(root->val);
  inorder(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  inorder(root, res);
  return res;
}
*/

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  root->right->right = nullptr;
  root->right->left->left = nullptr;
  root->right->left->right = nullptr;
  vector<int> ans = inorderTraversal(root);

  return 0;
}