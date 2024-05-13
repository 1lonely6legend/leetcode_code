//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() == 0) return {};//如果区间为空，返回空
    //使用lambda表达式对区间进行排序，按照区间的左端点进行排序
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    vector<vector<int>> res;
    //首先将第一个区间加入结果数组，后面以此进行比较
    res.emplace_back(intervals[0]);
    //这里遍历要从1开始，因为第一个区间已经加入结果数组了
    for (int i = 1; i < intervals.size(); ++i) {
      //如果当前区间的左端点小于等于结果数组的最后一个区间的右端点，说明有重叠
      if (res.back()[1] >= intervals[i][0]) {
        //更新结果数组的最后一个区间的右端点
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      } else {
        //如果没有重叠，直接加入结果数组
        res.emplace_back(intervals[i]);
      }
    }
    return res;
  }
};
