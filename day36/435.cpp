//
// Created by ogier on 23-11-29.
// 435.无重叠区间
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.size() == 1) return 0;
    sort(intervals.begin(),
         intervals.end(),
         [](const vector<int> &w1, const vector<int> &w2) { return w1[0] < w2[0]; });
    int res = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < intervals[i - 1][1]) {//如果当前范围和上一个范围重合
        //肯定要删除一个范围，但具体删除哪一个需要比较他们的上限大小，删除范围更大的
        if (intervals[i][1] >= intervals[i - 1][1]) {//当前范围的上限更大，删除当前
          intervals[i][1] = intervals[i - 1][1];//重新设置大小,方便后续比较
          intervals[i][0] = intervals[i - 1][0];
        }
        //前一个范围完全包住了当前范围，直接删除前一个,也就是不需要处理当前的
        res++;
      }
    }
    return res;
  }
};