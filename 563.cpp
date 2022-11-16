//
// Created by ogier on 2022/11/16.
//

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;//首先明确最终的返回值是各个节点计算的子树的差,设置一个全局变量,便于储存
int findTilt_son(TreeNode *root) {
  if (!root) return 0;//当遍历到空节点时,返回0;
  //进行一个前序遍历,分别将左子树节点和右子树节点的和拿到手
  int leftsum = findTilt_son(root->left);
  int rightsum = findTilt_son(root->right);
  //接下来就是计算当前root节点的左右子树和的差的绝对值
  ans += (leftsum - rightsum > 0) ? leftsum - rightsum : rightsum - leftsum;
  //虽然答案要的是各节点的子节点的和的差,但上游节点需要的是子节点的和,所以将当前节点的左右子树和以及自身val相加并返回
  return leftsum + rightsum + root->val;
}
int findTilt(TreeNode *root) {
  //其实这个rootcha没啥用,最高的一层函数已经加到ans里了.
  int root_cha = findTilt_son(root);//使用int类型的函数,便于递归时返回当前节点以及所有子节点的和
  return ans;
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(7);

  int ans = findTilt(root);

  return 0;
}