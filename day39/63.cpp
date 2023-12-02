//
// Created by ogier on 23-12-2.
// 63.不同路径II
#include <vector>
using std::vector;
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m][n];
    int flag = 1;
    for (int i = 0; i < m; ++i) {
      if (flag == 0) {
        dp[i][0] = 0;
        continue;
      }
      if (obstacleGrid[i][0] == 1)
        flag = 0;
      if (flag == 0)
        dp[i][0] = 0;
      else
        dp[i][0] = 1;
    }
    flag = 1;
    for (int i = 0; i < n; ++i) {
      if (flag == 0) {
        dp[0][i] = 0;
        continue;
      }
      if (obstacleGrid[0][i] == 1)
        flag = 0;
      if (flag == 0)
        dp[0][i] = 0;
      else
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

class Solutioncaral {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1)
      return 0;
    vector<int> dp(obstacleGrid[0].size());
    for (int j = 0; j < dp.size(); ++j)
      if (obstacleGrid[0][j] == 1)
        dp[j] = 0;
      else if (j == 0)
        dp[j] = 1;
      else
        dp[j] = dp[j-1];

    for (int i = 1; i < obstacleGrid.size(); ++i)
      for (int j = 0; j < dp.size(); ++j){
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else if (j != 0)
          dp[j] = dp[j] + dp[j-1];
      }
    return dp.back();
  }
};

int main() {
  vector<vector<int>> test = {{0, 0}, {1, 0}};
  Solution S;
  auto res = S.uniquePathsWithObstacles(test);
  return 0;
}