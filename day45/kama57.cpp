//
// Created by ogier on 2023/12/8.
// kama57.爬楼梯（第八期模拟笔试）
#include <vector>
#include <iostream>
using namespace std;

void climbStairs(int n, int m) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
	  if (i - j >= 0)
		dp[i] += dp[i - j];
	}
  }
  cout << dp[n];
}

int main() {
  int n, m;
  cin >> n >> m;
  climbStairs(n, m);
  return 0;
}