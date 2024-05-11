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
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    unordered_map<char, int> need, window;
    for (auto c : p) ++need[c];
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
      char c = s[right];
      ++right;
      if (need.count(c)) {
        ++window[c];
        if (window[c] == need[c])
          ++valid;
      }
      while (right - left >= p.size()) {
        if (valid == need.size())
          res.push_back(left);
        char d = s[left];
        ++left;
        if (need.count(d)) {
          if (window[d] == need[d])
            --valid;
          --window[d];
        }
      }
    }
    return res;
  }
};