//
// Created by ogier on 23-11-23.
// 332.重新安排行程
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <map>
using namespace std;
class Solution {
  public:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>&res) {
      if (res.size() == ticketNum + 1) {
        return true;
      }
      for (pair<const string, int>&target : targets[res[res.size() - 1]]) {
        if (target.second > 0) {
          res.push_back(target.first);
          target.second--;
          if (backtracking(ticketNum, res))
            return true;
          res.pop_back();
          target.second++;
        }
      }
      return false;
    }
    vector<string> findItinerary(vector<vector<string>>&tickets) {
      targets.clear();
      vector<string> res;
      for (const vector<string>&vec : tickets) {
        targets[vec[0]][vec[1]]++;
      }
      res.push_back("JFK");
      backtracking(tickets.size(), res);
      return res;
    }
};
