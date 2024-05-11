//
// Created by ogier on 24-4-22.
// 118.杨辉三角
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    for (int i = 1; i < numRows; ++i) {
        vector<int> temp(i + 1, 1);
        vector<int> pre = ans.back();
        for (int k = 1; k < i ; ++k) {
          temp[k] = pre[k - 1] + pre[k];
        }
        ans.push_back(temp);
    }
    return ans;
  }
};