//
// Created by ogier on 24-5-16.
//当前位置的最优解未必是由前一个位置的最优解转移得到的。
//根据正负性进行分类讨论。考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积也是个负数，
//这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，即尽可能小。如果当前位置是一个正数的话，
//我们更希望以它前一个位置结尾的某个段的积也是个正数，并且希望它尽可能地大。

#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProduct(vector<int> &nums) {
    //维护两个数组，一个存储以当前位置结尾的最大乘积，一个存储以当前位置结尾的最小乘积
    vector<int> maxdp(nums), mindp(nums);
    for (int i = 1; i < nums.size(); ++i) {
      maxdp[i] = max(maxdp[i - 1] * nums[i], max(nums[i], mindp[i - 1] * nums[i]));
      mindp[i] = min(mindp[i - 1] * nums[i], min(nums[i], maxdp[i - 1] * nums[i]));
    }
    return *max_element(maxdp.begin(),maxdp.end());
  }
};
