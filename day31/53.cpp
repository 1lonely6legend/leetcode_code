//
// Created by ogier on 23-11-24.
// 53.最大子数组和
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
  public:
    int maxSubArray(vector<int>&nums) {
      int res = INT32_MIN;
      int count = 0;
      for (int i = 0; i < nums.size(); ++i) {
        count += nums[i];
        if (count > res)
          res = count;
        if (count <= 0)count = 0;
      }
      return res;
    }
};
int main() {
  vector<int> test = {-2, -1};
  Solution S;
  auto res = S.maxSubArray(test);
  return 0;
}
