//
// Created by ogier on 24-3-30.
//
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    for (const int &num : nums) {
      set.insert(num);
    }
    int longestStreak = 0;
    for (const int &num : nums) {
      if (!set.count(num - 1)) {
        //数组中没有num-1这个数，重新开始计数
        int currentNum = num;
        int currentStreak = 1;
        while (set.count(currentNum + 1)) {
          currentNum += 1;
          currentStreak += 1;
        }
        longestStreak = max(longestStreak, currentStreak);
      }
    }
    return longestStreak;
  }
};