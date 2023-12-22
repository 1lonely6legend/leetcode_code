//
// Created by ogier on 23-12-22
//
#include <vector>
#include <stack>
using namespace std;
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> res(nums.size(), -1);
    if (nums.size() == 0) return res;
    stack<int> stk;
    for (int i = 0; i < nums.size() * 2; ++i) {
      //使用取模的方式来模拟这个成环的处理
      while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
        res[stk.top()] = nums[i % nums.size()];
        stk.pop();
      }
      stk.push(i % nums.size());
    }
    return res;
  }
};

