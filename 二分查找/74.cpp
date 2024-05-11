//
// Created by ogier on 24-5-11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int l = 0, r = row * col - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      int x = matrix[mid / col][mid % col];
      if (x > target) {
        r = mid - 1;
      } else if (x < target) {
        l = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};