//
// Created by ogier on 2023/12/6.
// 1049.最后一块石头的重量Ⅱ
#include <vector>
using namespace std;
class Solution {
 public:
  int lastStoneWeightII(vector<int> &stones) {
	int sum = 0;
	for (int a : stones)
	  sum += a;
	int target = sum / 2;

	vector<int> dp(15001,0);
	for (int i = 0;i<stones.size();++i){
	  for(int j = target;j>=stones[i];--j){
		dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
	  }
	}
	return sum-dp[target]-dp[target];
  }
};