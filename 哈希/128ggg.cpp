//
// Created by ogier on 24-5-11.
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
    }//首先将所有的元素放入set中
    int longestStreak = 0;
    //接下来就是以下步骤：
//1.遍历数组中的每一个元素
//2.如果当前元素的前一个元素不在set中，那么就从当前元素开始，向后遍历，直到找到最长的连续序列
    for (const int &num : nums) {
      if (!set.count(num - 1)) {
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
