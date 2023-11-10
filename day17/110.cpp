// creat by ogier 2023/11/10
// 110.平衡二叉树
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
        int getHeight(TreeNode* node){
            if(node == nullptr) return 0;
            int leftHeight = getHeight(node->left);
            if(leftHeight == -1) return -1;
            int rightHeight = getHeight(node->right);
            if(rightHeight == -1) return -1;
            return abs(leftHeight- rightHeight)>1?-1:1+max(leftHeight,rightHeight);
            }
        bool isBalanced(TreeNode* root){
            return getHeight(root) == -1;
        }
};