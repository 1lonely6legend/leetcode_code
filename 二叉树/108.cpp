//
// Created by ogier on 24-5-15.
//
#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode *creat_tree(vector<int> &nums, int left, int right) {
      if (left > right) return nullptr;
      if (left == right) return new TreeNode(nums[left]);
      int mid = left + ((right - left) >> 1);
      return new TreeNode(nums[mid], creat_tree(nums, left, mid - 1), creat_tree(nums, mid + 1, right));
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
      return creat_tree(nums, 0, nums.size() - 1);
    }
};
