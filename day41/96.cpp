//
// Created by ogier on 23-12-4.
// 96.不同的搜索二叉树
#include <vector>
using std::vector;
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    //dp[i] += dp[j - 1] * dp[i - j]
    //j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
int main() {
  Solution S;
  auto res = S.numTrees(1);
  return 0;
}