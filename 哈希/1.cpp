//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) {
        res.emplace_back(i);
        res.emplace_back(map[target - nums[i]]);
        return res;
      } else {
        map[nums[i]] = i;
      }
    }
    return {0, 0};
  }
};
