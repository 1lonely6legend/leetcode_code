//二维dp数组实现
#include <bits/stdc++.h>
using namespace std;

int n, bagweight;// bagweight代表行李箱空间
void solve() {
  vector<int> weight(n, 0); // 存储每件物品所占空间
  vector<int> value(n, 0);  // 存储每件物品价值
  for(int i = 0; i < n; ++i) {
    cin >> weight[i];
  }
  for(int j = 0; j < n; ++j) {
    cin >> value[j];
  }
  // dp数组, dp[i][j]代表行李箱空间为j的情况下,从下标为[0, i]的物品里面任意取,能达到的最大价值
  vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

  // 初始化, 因为需要用到dp[i - 1]的值
  // j < weight[0]已在上方被初始化为0
  // j >= weight[0]的值就初始化为value[0]
  for (int j = weight[0]; j <= bagweight; j++) {
    dp[0][j] = value[0];
  }

  for(int i = 1; i < weight.size(); i++) { // 遍历科研物品
    for(int j = 0; j <= bagweight; j++) { // 遍历行李箱容量
      // 如果装不下这个物品,那么就继承dp[i - 1][j]的值
      if (j < weight[i]) dp[i][j] = dp[i - 1][j];
        // 如果能装下,就将值更新为 不装这个物品的最大值 和 装这个物品的最大值 中的 最大值
        // 装这个物品的最大值由容量为j - weight[i]的包任意放入序号为[0, i - 1]的最大值 + 该物品的价值构成
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }
  cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
  while(cin >> n >> bagweight) {
    solve();
  }
  return 0;
}