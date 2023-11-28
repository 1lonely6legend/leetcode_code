//
// Created by ogier on 23-11-28.
// 406.根据身高重建队列
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    list<vector<int>> res;
    auto iter = res.begin();
    sort(people.begin(), people.end(),
         [](const vector<int> &p1, const vector<int> &p2) {
           return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
         });
    for (int i = 0; i < people.size(); ++i) {
      int position = people[i][1];
      iter = res.begin();
      while(position--){
        iter++;
      }
      res.insert(iter, people[i]);
    }
    vector<vector<int>> res2(res.begin(), res.end());
    return res2;
  }
};