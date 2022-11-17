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

int ans, temp, lastnum;
void visit(TreeNode *root) {
  //先算差值是多少,在搞一个绝对值
  temp = (root->val - lastnum) > 0 ? root->val - lastnum : lastnum - root->val;
  if (temp < ans)//如果差值比一开始的小那么就取
    ans = temp;
  lastnum = root->val;//记录一下这个节点的值,方便后续对比
}
void TravIn(TreeNode *root) {//简单的中序遍历
  if (!root) return;
  TravIn(root->left);
  visit(root);
  TravIn(root->right);
}
int getMinimumDifference(TreeNode *root) {
  ans =     10000000;//因为要保证最小的结果,所以把初始值拉满
  lastnum = 1000000;//因为第一次计算得到的差没有意义,所以把第一次算的差拉满,这样第一个算出来的肯定不是最小的
  TravIn(root);//对搜索二叉树中序遍历即为有序数组
  return ans;
}

int main() {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(5);
  /*root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(7);*/

  int ans = getMinimumDifference(root);
  cout << ans;
  return 0;
}