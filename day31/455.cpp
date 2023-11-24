//
// Created by ogier on 23-11-24.
// 455.分发饼干
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int findContentChildren(vector<int>&g, vector<int>&s) {
      sort(s.begin(), s.end());
      sort(g.begin(), g.end());
      int res = 0;
      for (int i = 0, j = 0; i < g.size() && j < s.size(); ++i, ++j) {
        if (s[i] >= g[i]) {
          ++res;
        }
        else {
          i--;
        }
      }
      return res;
    }
};

class betterSolution {
  public:
    int findContentChildren(vector<int>&g, vector<int>&s) {
      sort(s.begin(), s.end());
      sort(g.begin(), g.end());
      int index = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (index < g.size() && g[index] <= s[i]) {
          index++;
        }
      }
      return index;
    }
};
