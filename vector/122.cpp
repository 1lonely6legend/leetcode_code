//
// Created by ogier on 2023/4/15.
// 买卖股票的最佳时机 II

//画一个每天价格的折线图,只要任何一天比前一天的价格高,就把差值加到利润当中,最后就是结果
//从折线图能看出这种是最大的利润

#include <vector>
#include <iostream>

using std::vector;

int maxProfit(vector<int> &prices) {
  if (prices.size() == 1) return 0;
  int profit = 0;
  auto p1 = prices.begin();
  for (auto p2 = prices.begin() + 1; p2 < prices.end(); p2++) {
    if (*p2 >= *p1)
      profit += *p2 - *p1;
    p1++;
  }
  return profit;
}

int main() {
  vector<int> nums = {7,1,5,3,6,4};
  std::cout << maxProfit(nums);
  return 0;
}

