//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int price_min = INT_MAX;
    int res = 0;
    for (int price : prices) {
      res = max(res, price - price_min);
      price_min = min(price_min, price);
    }
    return res;
  }
};

int main() {
  vector<int> test = {7, 1, 5, 3, 6, 4};
  Solution S;
  int res = S.maxProfit(test);
  return 0;
}