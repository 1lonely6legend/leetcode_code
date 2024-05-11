//
// Created by ogier on 24-4-18.
// 200. 岛屿数量
#include <bits/stdc++.h>
using namespace std;
class SolutionDFS {
 public:
  int move[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &used, int x, int y) {
    for (int i = 0; i < 4; ++i) {
      int nextx = x + move[i][0];
      int nexty = y + move[i][1];
      if (nextx < 0 || nextx >= grid[0].size() || nexty < 0 || nexty >= grid.size()) continue;
      if (grid[nexty][nextx] == '1' && !used[nexty][nextx]) {
        used[nexty][nextx] = true;
        dfs(grid, used, nextx, nexty);
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> used(row, vector<bool>(col, false));
    int res = 0;
    for (int j = 0; j < row; ++j) {
      for (int i = 0; i < col; ++i) {
        if (grid[j][i] == '1' && !used[j][i]) {
          used[j][i] = true;
          res++;
          dfs(grid, used, i, j);
        }
      }
    }
    return res;
  }
};

class SolutionBFS {
 public:
  int move[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
  void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y) {
    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    visited[y][x] = true; //要在入队时就标记
    while (!que.empty()) {
      pair<int, int> cur = que.front();
      que.pop();
      int curx = cur.first;
      int cury = cur.second;
      for (int i = 0; i < 4; ++i) {
        int nextx = curx + move[i][0];
        int nexty = cury + move[i][1];
        if (nextx < 0 || nextx >= grid[0].size() || nexty < 0 || nexty >= grid.size()) continue;
        if (grid[nexty][nextx] == '1' && !visited[nexty][nextx]) {
          que.push(make_pair(nextx, nexty));
          visited[nexty][nextx] = true;
        }
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> used(row, vector<bool>(col, false));
    int res = 0;
    for (int j = 0; j < row; ++j) {
      for (int i = 0; i < col; ++i) {
        if (grid[j][i] == '1' && !used[j][i]) {
          used[j][i] = true;
          res++;
          bfs(grid, used, i, j);
        }
      }
    }
    return res;
  }
};