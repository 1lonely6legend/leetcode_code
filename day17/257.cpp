// creat by ogier 2023/11/10
// 257.二叉树的所有路径
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> path, vector<string> &result)
    {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
            if (cur->left)
            {
                // 如果当前节点的左子树存在
                traversal(cur->left, path, result);
                path.pop_back();
            }
            if (cur->right)
            {
                traversal(cur->right, path, result);
                path.pop_back();
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result; // 存放最终字符串
        vector<int> path;      // 存放遍历过程中的访问节点，使用int便于回溯
        if (root == nullptr)
            return result;
        // 需要先判断root是否唯空，在traversal中默认cur节点非空
        traversal(root, path, result);
        return result;
    }
};