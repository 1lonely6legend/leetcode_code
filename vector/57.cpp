//
// Created by ogier on 2023/5/25.
// 57. 插入区间,感觉就是56,插入一个区间,
// 还是看md把
//https://leetcode.cn/problems/insert-interval/solution/57-cha-ru-qu-jian-mo-ni-cha-ru-xiang-jie-by-carlsu/
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  intervals.push_back(newInterval);
  if (intervals.size() == 0)
    return {};
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> res;
  for (auto elem : intervals) {
    int L = elem[0], R = elem[1];
    if (res.size() == 0 || res.back()[1] < L) {
      res.push_back({L, R});
    } else {
      int tmp = res.back()[1];
      res.back()[1] = std::max(tmp, R);
    };
  }
  return res;
}

int main() {
  vector<vector<int>> intervals = {};
  vector<int> newInterval = {5,7};
  vector<vector<int>> res = insert(intervals, newInterval);
  for (auto &i : res) {
    for (auto &j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
