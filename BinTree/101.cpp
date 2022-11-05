//
// Created by ogier on 2022/11/4.
//
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool duibi(TreeNode *pl, TreeNode *pr) {
  if (pl == nullptr && pr == nullptr)
    return true;
  if (pl == nullptr || pr == nullptr)
    return false;
  if (pl->val != pr->val)
    return false;
  return duibi(pl->left, pr->right) && duibi(pl->right, pr->left);
}

bool isSymmetric(TreeNode *root) {
  //TreeNode *pl = root, *pr = root;，不需要直接传递 root root
  return duibi(root, root);
}
