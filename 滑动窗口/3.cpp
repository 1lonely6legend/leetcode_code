//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
//想清楚滑动窗口是什么，每次不合规的话，左边边界向右移动一次，右边继续移动
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.size();
    int res = 0;
    int r = 0;//滑动窗口右边界
    unordered_set<char> set;
    for (int i = 0; i < len; ++i) {
      while(r<len && set.find(s[r])==set.end()){
        set.insert(s[r]);
        ++r;
      }
      res = max(res,r-i);
      set.erase(s[i]);
    }
    return res;
  }
};

int main() {
  string s = "abcabcbb";
  Solution S;
  int res = S.lengthOfLongestSubstring(s);
  return 0;
}