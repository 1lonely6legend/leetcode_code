//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int hash[27] = {0};
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
      hash[s[i] - 'a'] = i;
    }
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); ++i) {
      r = max(r, hash[s[i] - 'a']);
      if (r == i) {
        res.emplace_back(r - l + 1);
        l = i + 1;
      }
    }
    return res;
  }
};