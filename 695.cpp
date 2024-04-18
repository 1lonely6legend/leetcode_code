//
// Created by ogier on 24-4-18.
// 695.岛屿的最大面积
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int move[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
  int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int y, int x) {
    int res = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    visited[y][x] = true;
    res++;
    while (!que.empty()) {
      pair<int, int> cur = que.front();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int nextx = cur.first + move[i][0];
        int nexty = cur.second + move[i][1];
        if (nextx < 0 || nextx >= grid[0].size() || nexty < 0 || nexty >= grid.size()) continue;
        if (grid[nexty][nextx] == 1 && !visited[nexty][nextx]) {
          que.push(make_pair(nextx, nexty));
          res++;
          visited[nexty][nextx] = true;
        }
      }
    }
    return res;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int res = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          visited[i][j] = true;
          res = max(res, bfs(grid, visited, i, j));
        }
      }
    }
    return res;
  }
};