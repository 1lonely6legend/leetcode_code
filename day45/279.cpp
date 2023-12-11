//
// Created by ogier on 2023/12/8.
// 279.完全平方数
#include <vector>
#include <iostream>
using namespace std;
class Solution {
 public:
  int numSquares(int n) {
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i * i <= n; ++i) {
	  for (int j = i * i; j <= n; ++j) {
		dp[j] = min(dp[j - i * i] + 1, dp[j]);
	  }
	}
	return dp[n];
  }
};

int main() {
  Solution S;
  auto res = S.numSquares(13);
  return 0;
}