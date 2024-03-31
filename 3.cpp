//
// Created by ogier on 24-3-31.
//
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<int> set;
    int res = 0;
    int RightPoint = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (i != 0) {
        set.erase(s[i - 1]);
      }
      while (RightPoint + 1 < s.size() && !set.count(s[RightPoint + 1])) {
        set.insert(s[RightPoint + 1]);
        ++RightPoint;
      }
      res = max(res, RightPoint - i + 1);
    }
    return res;
  }
};
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/9749/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-
class SolutionBetter {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> windows;
    int res = 0;
    int left = 0, right = 0;
    while (right < s.size()) {
      char c = s[right];
      ++right;
      ++windows[c];
      while (windows[c] > 1) {
        char d = s[left];
        ++left;
        --windows[d];
      }
      res = max(res, right - left);
    }
    return res;
  }
};