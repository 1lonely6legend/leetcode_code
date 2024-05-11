//
// Created by ogier on 24-4-22.
// 119.杨辉三角 II
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> dp(1, 1);
    for (int i = 2; i <= rowIndex + 1; ++i) {
      vector<int> temp(i, 1);
      for (int j = 1; j < i - 1; ++j) {
        temp[j] = dp[j - 1] + dp[j];
      }
      dp = temp;
    }
    return dp;
  }
};

int main() {
  Solution S;
  auto res = S.getRow(3);
  return 0;
}
