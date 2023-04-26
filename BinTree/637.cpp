//
// Created by ogier on 2022/11/21.
// 637. 二叉树的层平均值

#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<double> ans;
queue<TreeNode *> node;
void bfs(TreeNode *root) {
  if (!root) return;
  node.push(root);
  while (!node.empty()) {
    TreeNode *temp = node.front();
    node.pop();
    node.push(temp->left);
    node.push(temp->right);
  }

}
vector<double> averageOfLevels(TreeNode *root) {

}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  /*root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(7);*/

  vector ans = averageOfLevels(root);

  return 0;
}

//DFS
/*class Solution {
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    auto counts = vector<int>();//设计数组,记录每一层有几个节点
    auto sums = vector<double>();//记录每一层各个节点的值的和
    dfs(root, 0, counts, sums);//开始DFS
    auto averages = vector<double>();
    int size = sums.size();
    for (int i = 0; i < size; i++) {//求均值
      averages.push_back(sums[i] / counts[i]);
    }
    return averages;
  }

  void dfs(TreeNode *root, int level, vector<int> &counts, vector<double> &sums) {
    if (root == nullptr) {//节点为空时,遍历结束
      return;
    }
    if (level < sums.size()) {//判断层数和nums数组是否一致,也就是这一层有没有被遍历过
      //因为dfs首先是把每一层最左边的节点走一边
      sums[level] += root->val;
      counts[level] += 1;
    } else {//如果大于,说明这里还没遍历过,
      sums.push_back(1.0 * root->val);//在数组中添加新的元素
      counts.push_back(1);
    }
    dfs(root->left, level + 1, counts, sums);
    dfs(root->right, level + 1, counts, sums);
  }
};*/

//BFS
//确保每次都把这一层的所有节点都取出来,然后计算均值,
//在把这些节点的所有子结点压入队列
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    auto averages = vector<double>();//存储每一行的均值
    auto q = queue<TreeNode*>();//维护一个节点队列,BFS用
    q.push(root);//BFS首先从根节点开始
    while (!q.empty()) {//只要队列不空就说明还没有遍历完
      double sum = 0;
      int size = q.size();//记录当前队列中的节点数量
      for (int i = 0; i < size; i++) {//遍历每一个节点,接下来就会遍历这一层的所有节点,并且同时压入新的节点
        //再循环中保证,新加入的子结点不会被访问,因为只会pop前size个节点
        auto node = q.front();
        q.pop();
        sum += node->val;
        auto left = node->left, right = node->right;
        if (left != nullptr) {
          q.push(left);
        }
        if (right != nullptr) {
          q.push(right);
        }
      }
      averages.push_back(sum / size);
    }
    return averages;
  }
};
