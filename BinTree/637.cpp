//
// Created by ogier on 2022/11/21.
//

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

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    auto counts = vector<int>();
    auto sums = vector<double>();
    dfs(root, 0, counts, sums);
    auto averages = vector<double>();
    int size = sums.size();
    for (int i = 0; i < size; i++) {
      averages.push_back(sums[i] / counts[i]);
    }
    return averages;
  }

  void dfs(TreeNode* root, int level, vector<int> &counts, vector<double> &sums) {
    if (root == nullptr) {
      return;
    }
    if (level < sums.size()) {
      sums[level] += root->val;
      counts[level] += 1;
    } else {
      sums.push_back(1.0 * root->val);
      counts.push_back(1);
    }
    dfs(root->left, level + 1, counts, sums);
    dfs(root->right, level + 1, counts, sums);
  }
};

class Solution {
 public List<Double> averageOfLevels(TreeNode root) {
    List<Double> averages = new ArrayList<Double>();
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.offer(root);
    while (!queue.isEmpty()) {
      double sum = 0;
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        TreeNode node = queue.poll();
        sum += node.val;
        TreeNode left = node.left, right = node.right;
        if (left != null) {
          queue.offer(left);
        }
        if (right != null) {
          queue.offer(right);
        }
      }
      averages.add(sum / size);
    }
    return averages;
  }
};
