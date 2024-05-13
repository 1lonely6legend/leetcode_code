//
// Created by ogier on 24-5-13.
//
#include <vector>
using namespace std;
class Solution {
  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      int x = 0, y = n - 1;
      while (x < m && y >= 0) {
        if (matrix[x][y] > target) {
          y--;
        } else if (matrix[x][y] < target) {
          x++;
        } else {
          return true;
        }
      }
      return false;
    }
};
