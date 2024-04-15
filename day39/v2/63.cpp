//
// Created by ogier on 24-4-11.
// 在初始化时需要考虑遇到障碍物之后都需要跳过
#include <bits/stdc++.h>
using namespace std;

class Solution1d {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i]) {
        break;
      } else {
        dp[i] = 1;
      }
    }

    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        if (obstacleGrid[j][i])
          dp[i] = 0;
        else if (i != 0)
          dp[i] += dp[i - 1];
      }
    }

    return dp[n - 1];
  }
};

class Solution2d {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //需要判断起点和终点是否有障碍物
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
      return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      if (obstacleGrid[0][i]) {
        //如果遇到一个障碍物，则初始化之后面的都是走不到的
        break;
      } else {
        dp[0][i] = 1;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (obstacleGrid[j][0]) {
        //如果遇到一个障碍物，则初始化之后面的都是走不到的
        break;
      } else {
        dp[j][0] = 1;
      }
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 1; i < n; ++i) {
        if (obstacleGrid[j][i]) {
          continue;
        } else {
          dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution1d S;
  vector<vector<int>> test = {{0, 0}, {1, 1}, {0, 0}};
  auto res = S.uniquePathsWithObstacles(test);
  return 0;
}