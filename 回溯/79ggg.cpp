//
// Created by ogier on 24-5-15.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    int rows = board.size(), cols = board[0].size();
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        //遍历矩阵，找到第一个字符相同的位置,然后从这个位置开始dfs
        // index表示当前要找的word的字符是第几个,从0开始
        if (board[r][c] == word[0] && dfs(board, word, 0, r, c)) {
          return true;
        }
      }
    }
    return false;
  }
  //函数作用是从board[row][col]开始，寻找word[index...word.size()-1]，返回是否找到
  bool dfs(vector<vector<char>> &board, string &word, int index, int row, int col) {
    if (index == word.size()) {//如果index等于word.size()，说明已经找到了
      return true;
    }
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
      //如果越界了，返回false
      return false;
    }
    if (board[row][col] != word[index]) {
      //如果当前字符不等于word[index]，返回false
      return false;
    }
    auto board_val = board[row][col];//定义一个变量保存当前board[row][col]的值
    board[row][col] = '0';//将当前board[row][col]的值置为0，表示已经访问过
    //下面递归寻找四个方向,如果有一个方向找到了，就返回true
    bool result = dfs(board, word, index + 1, row - 1, col);
    result = result || dfs(board, word, index + 1, row + 1, col);
    result = result || dfs(board, word, index + 1, row, col - 1);
    result = result || dfs(board, word, index + 1, row, col + 1);
    board[row][col] = board_val;//还原board[row][col]的值
    return result;
  }
};