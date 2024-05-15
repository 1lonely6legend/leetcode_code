//
// Created by ogier on 24-5-15.
//
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(int n, int k, int start) {
      if (path.size() == k) {
        res.emplace_back(path);
        return;
      }
      for (int i = start; i <= n; ++i) {
        path.emplace_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
      }
    }
    vector<vector<int> > combine(int n, int k) {
      res.clear();
      path.clear();
      backtracking(n, k, 1);
      return res;
    }
};
