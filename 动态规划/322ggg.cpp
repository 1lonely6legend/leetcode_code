//
// Created by ogier on 24-5-15.
//
#include <climits>
#include <vector>
using namespace std;
class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {       //首先遍历背包，也就是要凑的钱数
      for (int j = 0; j < coins.size(); ++j) {//然后遍历物品,也就是硬币,这里的物品是可以重复使用的,所以是0~coins.size()
        //这里终止条件是coins[j] <= i，因为如果coins[j] > i，那么就不可能凑出i这么多钱
        if (coins[j] <= i) {
          //这里的dp[i]是凑出i这么多钱需要的最少硬币数,等于凑出i-coins[j]这么多钱需要的最少硬币数+1
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    // 如果 dp[amount] 仍为初始值 INT_MAX，表示无法凑成该金额，返回 -1
    return dp[amount] > amount ? -1 : dp[amount];
  }
};