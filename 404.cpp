//
// Created by ogier on 2022/11/11.
//

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void TravIn(TreeNode *root, int &ans, int &status, int &temp) {
  //这个还是要加上的,要不可能会访问到nullptr->lest/right会报错
  //当该root节点两个孩子一个存在一个为nullptr时会出现这种情况
  if (!root) return;
  //判断当前节点是不是叶子节点
  if (root->left == nullptr && root->right == nullptr) {
    status = 1;//如果是叶子节点就将状态量设置为1
    temp = root->val;//将当前叶子节点的值存到temp中
    return;
  }
  TravIn(root->left, ans, status, temp);//首先是进行一个中序遍历,首先遍历左子树
  if (status == 1) {//把这个加到ans上的操作放在遍历左子树的上边
    //目的是如果此时status==1.那么这一定是从左叶子节点返回的,保证了不会把右叶子加上去
    ans += temp;
    //temp置为0我以为不是必要的,但发现会报错[7,-7,8,null,null,-3,6,null,9,null,null,null,-5]
    temp = 0;//将temp置为0,方便下次存储
  }
  TravIn(root->right, ans, status, temp);
  status = 0;//右子树遍历完记得把状态量设置为1,防止右子树的叶子节点被加进来
}

int sumOfLeftLeaves(TreeNode *root) {
  int ans = 0;//计数器
  int status = 0;//状态量,表示此时的这个节点是不是从叶子节点回溯过来的
  int temp = 0;//临时变量,叶子节点回溯之前把val值存一下
  //对二叉树进行中序遍历,因为找左节点吗,所以首先遍历到左节点,将状态量置为1
  //而后在根节点的位置进行判断,如果status==1,那么这个根节点的左节点是叶子节点(刚回溯过来的)
  //然后将temp量保存在ans中
  TravIn(root, ans, status, temp);
  return ans;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int ans = sumOfLeftLeaves(root);

  return 0;
}

/*
官解
class Solution {
 public:
  bool isLeafNode(TreeNode* node) {
    return !node->left && !node->right;
  }

  int dfs(TreeNode* node) {
    int ans = 0;
    if (node->left) {
      ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
    }
    if (node->right && !isLeafNode(node->right)) {
      ans += dfs(node->right);
    }
    return ans;
  }

  int sumOfLeftLeaves(TreeNode* root) {
    return root ? dfs(root) : 0;
  }
};
*/
