//
// Created by ogier on 23-11-25.
// 122.买卖股票的最佳时机II
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int res = 0;
    int pre = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > pre) {
        res += prices[i] - pre;
      }
      pre = prices[i];
    }
    return res;
  }
};

int main() {
  vector<int> test = {7, 1, 5, 3, 6, 4};
  Solution S;
  auto res = S.maxProfit(test);

  return 0;

}