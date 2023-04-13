//
// Created by ogier on 2023/4/13.
// 121. 买卖股票的最佳时机
#include <vector>
#include <iostream>

using std::vector;

int maxProfit(vector<int> &prices) {
  int min_price = 1000000;//首先因为是最低价格,所以要初始化一个大数
  int max_profit = 0; //因为是最低利润,并且当天买入卖出就是0,所以最大利润初始化为最小值0
  for (int num : prices) {
    max_profit = std::max(num - min_price, max_profit);
    min_price = std::min(num, min_price);
  }
  return max_profit;
}

int main() {
  vector<int> nums1 = {7, 1, 5, 3, 6, 4};
  int ans = maxProfit(nums1);
  std::cout << ans;
  return 0;
}