//
// Created by ogier on 2023/12/23.
// 84.柱状图中最大的矩形
#include <vector>
#include <stack>
using namespace std;
class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    int res = 0;
    stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stk.push(0);

    for (int i = 1; i < heights.size(); ++i) {
      if (heights[i] > heights[stk.top()]) {
        stk.push(i);
      } else if (heights[i] == heights[stk.top()]) {
        stk.pop();
        stk.push(i);
      } else {
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
          int mid = stk.top();
          stk.pop();
          if (!stk.empty()) {
            int left = stk.top();
            int right = i;
            int w = right - left - 1;
            int h = heights[mid];
            res = max(res, w * h);
          }
        }
        stk.push(i);
      }
    }
    return res;
  }
};