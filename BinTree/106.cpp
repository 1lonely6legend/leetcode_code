//
// Created by ogier on 2023/10/12.
// 106.从中序与后遍历序列构造二叉树
// 关键就是一个来回的切割问题

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0)
      return nullptr;
    return traverse(inorder, postorder);
  }

private:
  TreeNode *traverse(vector<int> &inorder, vector<int> &postorder) {

    // 如果数组为空直接返回空指针,不空的话直接找后序遍历的最后一个就是根节点
    if (postorder.size() == 0)
      return nullptr;
    int rootValue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootValue);

    // 如果后序数组只有一个数字,那二叉树也只有一个节点
    if (postorder.size() == 1)
      return root;

    // 在前序数组中查找根节点的位置,开始为分割做准备
    int delimiterIndex = 0;
    for (; delimiterIndex < inorder.size(); delimiterIndex++) {
      if (inorder[delimiterIndex] == rootValue)
        break;
    }

    // 中序数组分割:直接使用中序遍历的下标初始化,分割数组,注意找开闭,我选择左闭右开
    //[0,delimiterIndex)
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    //[delimiterIndex+1,end),这里是去掉了一个中间数,所以要加一
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,
                             inorder.end());

    // 后序数组分割,直接使用中序数组分出来的两个数组的个数
    postorder.pop_back();
    vector<int> leftPostorder(postorder.begin(),
                              postorder.begin() + leftInorder.size());
    vector<int> rightPoster(postorder.begin() + leftInorder.size(),
                            postorder.end());
    root->left = traverse(leftInorder, leftPostorder);
    root->right = traverse(rightInorder, rightPoster);

    return root;
  }
};

int main() { return 0; }
