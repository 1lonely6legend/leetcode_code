//
// Created by ogier on 24-5-13.
//
/*
 *装多少水是由最短边决定的，为什么最短边移动，是因为如果长边移动，那么装的水可能会少，
 *（因为由最短边决定，无论你长边移动后高度增加或者减少，都只能是装水量变少。）不可能会多。而如果移动最短边，那么有可能能够装更多的水。
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
      int i = 0, j = height.size() - 1;
      int res = 0;
      while (i < j) {
        res = height[i] <= height[j] ? max(res, (j - i) * height[i++]) : max(res, (j - i) * height[j--]);
      }
      return res;
    }
};
