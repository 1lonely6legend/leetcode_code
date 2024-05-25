//
// Created by ogier on 24-5-25.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
    int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    function<bool(int, int, int)> dfs = [&](int x, int y, int length)-> bool {
      if (length == word.size()) {
        return true;
      }
      if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[length] || used[x][y]) {
        return false;
      }
      used[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int nx = x + move[i][0];
        int ny = y + move[i][1];
        if (dfs(nx, ny, length + 1))
          return true;
      }
      used[x][y] = false;
      return false;
    };
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0] && dfs(i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
