//
// Created by ogier on 23-11-27.
// 1005.K次取反后最大化的数组和
#include<vector>
#include <queue>
#include<algorithm>
using namespace std;
class Solution {
 public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> prio_que(nums.begin(), nums.end());
    while (k != 0) {
      int cur = prio_que.top();
      prio_que.pop();
      prio_que.push(-cur);
      k--;
    }
    int res = 0;
    while (!prio_que.empty()) {
      res += prio_que.top();
      prio_que.pop();
    }
    return res;
  }
};
