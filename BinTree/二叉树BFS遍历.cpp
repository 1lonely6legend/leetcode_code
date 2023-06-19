//
// Created by ogier on 2023/6/16.
//使用一个队列来实现BFS
#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;//初始化一个队列,FIFO
    if (root != nullptr) que.push(root);//如果树不是空的就压入根节点
    vector<vector<int>> res;//初始化返回的数组
    while (!que.empty()) {//当队列不空时,持续弹出,处理,添加其子节点
      int size = que.size();//当前队列中的元素数量
      vector<int> vec;//初始化存放一层数据的数组
      for (int i = 0; i < size; i++) {//遍历这一层的所有数组,如果有叶子节点的就新加入队列当中
        //这样一个循环走完之后保证这一层的所有元素都遍历完毕,新添加的都是下一层的节点
        TreeNode *node = que.front();//取出节点
        que.pop();//在队列中删除
        vec.push_back(node->val);//将数据存入数组中
        if (node->left) que.push(node->left);//如果左右节点存在就放入队列中
        if (node->right) que.push(node->right);
      }
      res.push_back(vec);//将这一层的数组加入最后的结果
    }
    return res;
  }
};