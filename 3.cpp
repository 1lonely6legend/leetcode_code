//
// Created by ogier on 24-3-31.
//
#include <string>
#include <unordered_set>
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
      res = max(res,RightPoint - i + 1);
    }
    return res;
  }
};
