//
// Created by ogier on 23-12-2.
// 62.不同路径
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    int DP[m][n];
    //需要初始化dp，也就是第一行if中直接返回的时候，在本题中，边缘都只有一种走法，直着走
    for (int i = 0; i < m; ++i) DP[i][0] = 1;
    for (int j = 0; j < n; ++j) DP[0][j] = 1;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
      }
    }
    return DP[m - 1][n - 1];
  }
};
int main() {
  Solution S;
  auto res = S.uniquePaths(3, 3);
  return 0;
}