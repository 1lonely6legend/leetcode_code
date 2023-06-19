//
// Created by ogier on 2023/6/16.
//
#include <iostream>
#include <vector>
#include <stack>
using std::cout;
using std::endl;
using std::vector;
using std::stack;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//前序遍历
class PreorderTraversal {
 public:
  vector<int> preorder_traversal(TreeNode *root) {
    stack<TreeNode *> stk;//申请一个栈,保存已经遍历到,但不是前序顺序的节点
    vector<int> res;//答案数组
    if (root == nullptr) return res;//树为空直接返回空数组
    stk.push(root);//首先将根节点放入数组
    while (!stk.empty()) {//如果存储的栈不空就一直处理下去
      TreeNode *node = stk.top();//首先取出栈顶的元素
      stk.pop();
      res.push_back(node->val);//前序遍历,首先读取
      if (node->right) stk.push(node->right);//因为栈是FILO所以先右后左
      if (node->left) stk.push(node->left);
    }
    return res;
  }
};

//中序遍历,左中右
class InorderTraversal {
 public:
  vector<int> inorder_traversal(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<int> res;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty()) {
      if (cur != nullptr) {//指针来访问节点,直到最低端
        stk.push(cur);//将访问的当前节点入栈
        cur = cur->left;//左
      } else {
        cur = stk.top();//从栈中pop的节点就是要处理的数据
        stk.pop();
        res.push_back(cur->val);//中
        cur = cur->right;//右
      }
    }
    return res;
  }
};
//后序遍历
class PostorderTraversal {
 public:
  vector<int> postorder_traversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      result.push_back(node->val);
      if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）中右左出,
      if (node->right) st.push(node->right); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果中右左反转之后就是左右中的顺序了
    return result;
  }
};
