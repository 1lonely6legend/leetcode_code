//
// Created by ogier on 24-5-13.
//
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int> > generateMatrix(int n) {
      int l = 0, u = 0, r = n - 1, d = n - 1;
      int content = 1;
      vector<vector<int> > mat(n, vector<int>(n, 0));
      while (true) {
        for (int i = l; i <= r; ++i) mat[u][i] = content++;
        if (++u > d) break;
        for (int i = u; i <= d; ++i) mat[i][r] = content++;
        if (--r < l) break;
        for (int i = r; i >= l; --i) mat[d][i] = content++;
        if (--d < u) break;
        for (int i = d; i >= u; --i) mat[i][l] = content++;
        if (++l > r) break;
      }
      return mat;
    }
};
