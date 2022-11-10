//
// Created by ogier on 2022/11/9.
//

//不知道为什么,现在main里面这个二叉树clion里是flse,leetcode中就是true nmmd

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool TravPre(TreeNode *root, int targetSum, int &temp) {
  temp += root->val;
  if (root->left == nullptr && root->right == nullptr) {//当访问到叶子节点时
    if (temp == targetSum) {
      temp -= root->val;
      return true;
    } else {
      temp -= root->val;
      return false;
    }
  }
  if (root->right != nullptr && root->left != nullptr)
    return (TravPre(root->left, targetSum, temp) || TravPre(root->right, targetSum, temp));
  else if (root->right == nullptr && root->left != nullptr)
    return TravPre(root->left, targetSum, temp);
  else
    return TravPre(root->right, targetSum, temp);
}

/*bool hasPathSum(TreeNode *root, int targetSum) {
  int temp = 0;
  if (root == nullptr)
    return false;
  else
    return TravPre(root, targetSum, temp);
}*/

///////////leetcode官方递归

bool hasPathSum(TreeNode *root, int targetSum) {
  if (root == nullptr)
    return false;
  if (root->left == nullptr && root->right == nullptr)
    return root->val == targetSum;
  return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}


int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(-3);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(-2);

  root->left->left->left = new TreeNode(-1);
  bool ans = hasPathSum(root, 0);

  return 0;
}


