//
// Created by ogier on 24-3-30.
//
#include <vector>
using namespace std;
class Solution {
 public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1, res = 0;
    while (i < j) {
      res = height[i] < height[j] ?
            //注意这里一定要先计算j-i，在进行++/--
            max(res, (j - i) * height[i++]) :
            max(res, (j - i) * height[j--]);
    }
    return res;
  }
};