//
// Created by ogier on 23-12-1.
// 746.使用最小花费爬楼梯
#include <vector>
using namespace std;
class Solution {
 public:
  int minCostClimbingStairs(vector<int> &cost) {
    int size = cost.size();
    if (size == 2) return min(cost[0], cost[1]);
    vector<int> dp;
    dp.resize(size+1);//要多写一步，这样计算的才是走到楼梯顶的值
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= size; ++i) {
      dp[i]= min(dp[i-2] + cost[i - 2], dp[i-1] + cost[i - 1]);
    }
    return dp.back();
  }
};

int main(){
  vector<int> test = {1,100,1,1,1,100,1,1,100,1};
  Solution S;
  auto res = S.minCostClimbingStairs(test);
  return 0;
}