//
// Created by ogier on 2024/4/7.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;
class Solution {
 public:
  struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
      return a.second > b.second;
    }
  };
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minheap;
    for (auto num : nums)
      map[num]++;
    for (auto iter : map) {
      minheap.push(pair<int, int>(iter.first, iter.second));
      if (minheap.size() > k)
        minheap.pop();
    }
    vector<int> res(k, 0);//设置k个0;
    //vector<int> res(k);//设置大小为k
    for (int i = k - 1; i >= 0; --i) {
      res[i] = minheap.top().first;
      minheap.pop();
    }
    return res;
  }
};