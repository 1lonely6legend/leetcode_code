//
// Created by ogier on 23-11-29.
// 56. 合并区间
#include <vector>
#include <algorithm>
using namespace std;

class SolutionGPT {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (const vector<int>& interval : intervals) {
      // 如果结果集为空或当前区间与结果集中最后一个区间不重叠，则直接添加
      if (merged.empty() || merged.back()[1] < interval[0]) {
        merged.push_back(interval);
      } else {
        // 否则，合并当前区间与结果集中最后一个区间
        merged.back()[1] = max(merged.back()[1], interval[1]);
      }
    }
    return merged;
  }
};
