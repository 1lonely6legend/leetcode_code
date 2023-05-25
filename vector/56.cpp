//
// Created by ogier on 2023/5/24.
// 56. 合并区间 最后还是看的答案
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  if (intervals.size() == 0) {
    return {};
  }
  // 原来直接使用sort可以直接按interval[i][0]进行排序
  //  不过我自己写的时候使用了map,不过应该没有这个快
  sort(intervals.begin(), intervals.end());
  // 初始化要返回的数组
  vector<vector<int>> merged;

  // 遍历排序之后的每一个区间
  for (int i = 0; i < intervals.size(); ++i) {
    // 取这个区间的左右端点
    int L = intervals[i][0], R = intervals[i][1];

    if (merged.size() == 0 || merged.back()[1] < L) {
      //如果答案数组还没有第一个区间,或者答案数组的最后一个区间的右端点小于当前区间的左端点
      //此时说明两个区间没有交集,将当前区间放入答案数组
      merged.push_back({L, R});
    } else {
      // 否则,说明两个区间有交集,将答案数组的最后一个区间的右端点更新为当前区间的右端点和答案数组的最后一个区间的右端点的最大值
      merged.back()[1] = std::max(merged.back()[1], R);
    }
  }
  return merged;
}

int main() {
  vector<vector<int>> intervals = {{8, 10}, {2, 6}, {1, 3}, {15, 18}};
  auto res = merge(intervals);
  return 0;
}
