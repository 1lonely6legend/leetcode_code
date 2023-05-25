//
// Created by ogier on 2023/5/25.
// 452. 用最少数量的箭引爆气球
// 翻译翻译题目的意思,首先合并区间,最后找合并的区间有多少个,这个不是跟56一样,秒了,tmd也不太一样
// 不是找合并的区间,而是找这些区间的交叉区间的个数,稍微改一下56的程序就可以了,
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

int findMinArrowShots(vector<vector<int>> &points) {
  vector<vector<int>> res;
  sort(points.begin(), points.end());
  for (auto elem : points) {
    int L = elem[0], R = elem[1];
    if (res.size() == 0 || res.back()[1] < L) {
      res.push_back({L, R});
    } else {
      //与56不同的地方就是这里了,两个区间的左端点取大的,右端点取小的,这样就是交叉区间
      res.back()[0] = std::max(res.back()[0], L);
      res.back()[1] = std::min(res.back()[1], R);
    }
  }
  return res.size();
}

int main() {
  vector<vector<int>> points = {{1, 2}};
  std::cout << findMinArrowShots(points) << std::endl;
  return 0;
}

