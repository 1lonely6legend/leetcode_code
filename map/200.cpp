//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <queue>
using namespace std;
class SolutionDFS {
  public:
    int move[4][2] = {0, 1, -1, 0, 1, 0, 0, -1};
    void DFS(vector<vector<char> > &grid, vector<vector<bool> > &visited, int x, int y) {
      for (int i = 0; i < 4; ++i) {
        int next_x = x + move[i][0];
        int next_y = y + move[i][1];
        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
          continue;
        if (!visited[next_x][next_y] && grid[next_x][next_y] == '1') {
          visited[next_x][next_y] = true;
          DFS(grid, visited, next_x, next_y);
        }
      }
    }
    int numIslands(vector<vector<char> > &grid) {
      int row = grid.size();
      int col = grid[0].size();
      int res = 0;
      vector<vector<bool> > visited(row, (vector<bool>(col, false)));
      for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
          if (!visited[i][j] && grid[i][j] == '1') {
            visited[i][j] = true;
            res++;
            DFS(grid, visited, i, j);
          }
        }
      }
      return res;
    }
};

class SolutionBFS {
  public:
    int move[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void BFS(vector<vector<char> > &grid, vector<vector<bool> > &visited, int x, int y) {
      queue<pair<int, int> > que;
      visited[x][y] = true;
      que.push(make_pair(x, y));
      while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; ++i) {
          int next_x = cur_x + move[i][0];
          int next_y = cur_y + move[i][1];
          if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
            continue;
          if (!visited[next_x][next_y] && grid[next_x][next_y] == '1') {
            visited[next_x][next_y] = true;
            que.push({next_x, next_y});
          }
        }
      }
    }
    int numIslands(vector<vector<char> > &grid) {
      int row = grid.size();
      int col = grid[0].size();
      int res = 0;
      vector<vector<bool> > visited(row, (vector<bool>(col, false)));
      for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
          if (!visited[i][j] && grid[i][j] == '1') {
            res++;
            BFS(grid, visited, i, j);
          }
        }
      }
      return res;
    }
};
