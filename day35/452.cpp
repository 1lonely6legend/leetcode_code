//
// Created by ogier on 23-11-28.
// 452.用最少数量的箭引爆气球
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;
    int res = 1;
    sort(points.begin(), points.end(),
         [](const vector<int>& p1, const vector<int>& p2) {
           return p1[0] < p2[0];
         });
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > points[i-1][1])
        res++;
      else
        points[i][1] = min(points[i][1], points[i - 1][1]);
    }
    return res;
  }
};