//
// Created by ogier on 23-11-23.
// 51.N皇后
#include <vector>
#include <string>
using namespace std;
class Solution {
  private:
    bool isValid(int row, int col, vector<string>&chessboard, int n) {
      //每一行取一个位置，行不需要检查
      //检查是否同一列
      for (int i = 0; i < row; ++i) {
        if (chessboard[i][col] == 'Q')
          return false;
      }
      //检查45度对角线左上右下
      for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q')
          return false;
      }
      //检查135度对角线
      for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q')
          return false;
      }
      return true;
    }

  public:
    vector<vector<string>> res;
    void backtracking(const int n, int row, vector<string>&chessboard) {
      if (row == n) {
        res.push_back(chessboard);
        return;
      }
      for (int col = 0; col < n; ++col) {
        //col列 row行
        if (isValid(row, col, chessboard, n)) {
          chessboard[row][col] = 'Q';
          backtracking(n, row + 1, chessboard);
          chessboard[row][col] = '.';
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      res.clear();
      vector<string> chessboard(n, string(n, '.'));
      backtracking(n, 0, chessboard);
      return res;
    }
};
