//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    struct cmp {
      bool operator()(const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; }
    };
    vector<int> topKFrequent(vector<int> &nums, int k) {
      unordered_map<int, int> map;
      for (int num : nums) {
        map[num]++;
      }
      priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
      for (pair<int, int> pair : map) {
        pq.push(pair);
        while (pq.size() > k) {
          pq.pop();
        }
      }
      vector<int> res;
      while (!pq.empty()) {
        res.push_back(pq.top().first);
        pq.pop();
      }
      return res;
    }
};
