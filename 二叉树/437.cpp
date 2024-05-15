//
// Created by ogier on 24-5-15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
  }
};
class Solution {
  public:
    int countPaths(TreeNode *root, int targetSum) {
      if (root == nullptr)return 0;
      int count = 0;
      if (root->val == targetSum) {
        count++;
      }
      count += countPaths(root->left, targetSum - root->val);
      count += countPaths(root->right, targetSum - root->val);
      return count;
    }
    int pathSum(TreeNode *root, int targetSum) {
      if (root == nullptr)
        return 0;
      int count = countPaths(root, targetSum);
      count += pathSum(root->left, targetSum);
      count += pathSum(root->right, targetSum);
      return count;
    }
};
class Solution2 {
  public:
  unordered_map<long long, int> prefix; //使用一个哈希表存储前缀和出现的次数
  int dfs(TreeNode *root, long long curr, int targetSum) {
    if (!root) {
      return 0; //如果节点为空，返回0
    }

    int ret = 0; //用于记录满足条件的路径数
    curr += root->val; //更新当前前缀和
    //检查是否存在前缀和使得当前路径和等于targetSum
    if (prefix.count(curr - targetSum)) {
      //如果哈希表中存在前缀和为curr-targetSum的路径，则更新ret
      ret = prefix[curr - targetSum];
    }

    //更新哈希表中前缀和为curr的路径数
    prefix[curr]++;
    ret += dfs(root->left, curr, targetSum); //递归左子树
    ret += dfs(root->right, curr, targetSum); //递归右子树
    prefix[curr]--; //回溯，将当前节点的前缀和数目减一
    return ret;
  }
  int pathSum(TreeNode *root, int targetSum) {
    prefix[0] = 1;
    return dfs(root, 0, targetSum);
  }
};