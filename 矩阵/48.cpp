//
// Created by ogier on 24-5-13.
//
#include <vector>
using namespace std;
//原地旋转90°，则首先水平翻转，在沿主对角线翻转一次即可
class Solution {
  public:
    void rotate(vector<vector<int> > &matrix) {
      int n = matrix.size();
      for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
          //注意这里需要n-i-1，因为是从0开始的
          swap(matrix[i][j], matrix[n - i - 1][j]);
        }
      }
      for (int i = 0; i < n; ++i) {
        //沿着对角线翻转，j<i，因为对角线左上角的元素不需要动，换一次就行
        for (int j = 0; j < i; ++j) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }
    }
};
