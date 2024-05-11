//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string >> map;
    vector<vector<string >> res;
    for (int i = 0; i < strs.size(); ++i) {
      string s = strs[i];
      sort(s.begin(), s.end());
      map[s].push_back(strs[i]);
    }
    int index = 0;
    for (auto iter : map) {
      res.emplace_back(iter.second);
    }
    return res;
  }
};