//
// Created by ogier on 2022/11/10.
//
#include<vector>
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//前序便利,注意一下传入引用就差不多了
void travpre(TreeNode *root, vector<int> &ans) {
  if (!root)
    return;
  ans.push_back(root->val);//因为是前序 写在前面

  ////////////之前的写法,感觉不太好
  /*
  if (!root)
    return;
  else
    ans.push_back(root->val);
  */
  /////////////////////
  travpre(root->left, ans);
  travpre(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;
  travpre(root, ans);
  return ans;
}
