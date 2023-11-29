//
// Created by ogier on 23-11-29.
// 763.划分字母区间
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int map[27] = {0};
    for (int i = 0; i < s.length(); ++i) {
      map[s[i] - 'a'] = i;
    }
    vector<int> res;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.length(); ++i) {
      right = max(right, map[s[i] - 'a']);
      if (i == right) {
        res.push_back(right - left + 1);
        left = i + 1;
      }
    }
    return res;
  }
};