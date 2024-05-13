//
// Created by ogier on 24-5-13.
//
#include <vector>
using namespace std;
class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row_zero, col_zero;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          row_zero.emplace_back(i);
          col_zero.emplace_back(j);
        }
      }
    }
    for (int num : row_zero) {
      for (int j = 0; j < n; ++j) {
        matrix[num][j] = 0;
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int num : col_zero) {
        matrix[i][num] = 0;
      }
    }
  }
};

int main() {
  vector<vector<int>> test = {{1,1,1},{1,0,1},{1,1,1}};
  Solution S;
  S.setZeroes(test);
  return 0;
}