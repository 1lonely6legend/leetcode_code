//
// Created by ogier on 2023/10/9.
// 513. 找树左下角的值
#include <iostream>
#include <queue>
#include <stack>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que;
        que.push(root);
        vector<int> res;
        int num = que.size();
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.clear();
        }
        return res[0];
    }
};

int main() {
    class Solution S;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    int res = 0;
    res = S.findBottomLeftValue(root);
    cout << res << endl;
    return 0;
}
