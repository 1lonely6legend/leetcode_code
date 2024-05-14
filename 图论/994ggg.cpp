//
// Created by ogier on 24-5-14.
//https://leetcode.cn/problems/rotting-oranges/solutions/2773461/duo-yuan-bfsfu-ti-dan-pythonjavacgojsrus-yfmh
#include <vector>
#include <queue>
using namespace std;
class Solution {
  int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 四方向

  public:
    int orangesRotting(vector<vector<int> > &grid) {
      int m = grid.size(), n = grid[0].size();
      int fresh = 0;
      vector<pair<int, int> > q;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == 1) {
            fresh++; // 统计新鲜橘子个数
          } else if (grid[i][j] == 2) {
            q.emplace_back(i, j); // 一开始就腐烂的橘子
          }
        }
      }

      int ans = -1;
      while (!q.empty()) {
        ans++; // 经过一分钟
        vector<pair<int, int> > nxt;
        for (auto &[x, y] : q) {
          // 已经腐烂的橘子
          for (auto d : DIRECTIONS) {
            // 四方向
            int i = x + d[0], j = y + d[1];
            if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
              // 新鲜橘子
              fresh--;
              grid[i][j] = 2; // 变成腐烂橘子
              nxt.emplace_back(i, j);
            }
          }
        }
        q = move(nxt);
      }

      return fresh ? -1 : max(ans, 0);
    }
};
