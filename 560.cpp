//
// Created by ogier on 24-3-31.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    map[0] = 1;
    int count = 0, sum = 0;
    for (auto &x : nums) {
      sum += x;
      if (map.find(sum - k) != map.end())
        count += map[sum - k];
      map[sum]++;
    }
    return count;
  }
};