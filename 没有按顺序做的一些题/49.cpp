#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); ++i) {
      string s = strs[i];
      sort(s.begin(), s.end());
      map[s].push_back(strs[i]);
    }
    int index = 0;
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
      res.emplace_back(iter->second);
    }
    return res;
  }
};
