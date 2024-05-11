//
// Created by ogier on 24-3-31.
//
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/9749/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    bool res = false;
    unordered_map<char, int> need, windows;
    for (auto c : s1) ++need[c];
    int left = 0, right = 0;
    int valid = 0;
    while (right < s2.size()) {
      char c = s2[right];
      ++right;
      if (need.count(c)) {
        ++windows[c];
        if (windows[c]== need[c]) {
          ++valid;
        }
      }

      while (right - left >= s1.size()) {
        if (valid == need.size()) {
          res = true;
        }
        char d = s2[left];
        ++left;
        if (need.count(d)) {
          if (windows[d]== need[d])
            --valid;
          --windows[d];
        }
      }
    }
    return res;
  }
};