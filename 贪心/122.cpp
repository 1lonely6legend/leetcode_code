//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      int diff = prices[i + 1] - prices[i];
      if (diff > 0) {
        res += diff;
      }
    }
    return res;
  }
};