//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size());
    // answer[i] 表示索引 i 左侧所有元素的乘积
    // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
    res[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
      res[i] = nums[i - 1] * res[i - 1];
    }
    // R 为右侧所有元素的乘积
    // 刚开始右边没有元素，所以 R = 1
    int R = 1;
    for (int i = nums.size() - 1;i>=0;--i) {
      res[i] = res[i]*R;
      R*= nums[i];
    }
    return res;
  }
};