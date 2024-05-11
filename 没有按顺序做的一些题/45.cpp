//
// Created by ogier on 2024/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
 public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1) return 0;
    int curdistance = 0;
    int ans = 0;
    int nextdistance = 0;
    for (int i = 0; i < nums.size(); ++i) {
      nextdistance = max(i + nums[i], nextdistance);
      if (i == curdistance) {
        ans++;
        curdistance = nextdistance;
        if (nextdistance >= nums.size() - 1) break;
      }
    }
    return ans;
  }
};

class Solution2 {
  //利用最后总是能走到终点的题目条件
 public:
  int jump(vector<int> &nums) {
    int curDistance = 0;    // 当前覆盖的最远距离下标
    int ans = 0;            // 记录走的最大步数
    int nextDistance = 0;   // 下一步覆盖的最远距离下标
    for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
      nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
      if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
        curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
        ans++;
      }
    }
    return ans;
  }
};