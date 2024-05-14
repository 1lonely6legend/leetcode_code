//
// Created by ogier on 24-5-14.
//https://blog.csdn.net/Zolewit/article/details/88863970
#include <stack>
#include <climits>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
      heights.push_back(0); //首先在heights数组末尾添加一个0，这样可以保证所有的元素都可以被弹出
      stack<int> stk;
      int maxArea = 0;
      for (int i = 0; i < heights.size(); i++) {
        //遍历heights数组
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
          //维护一个单调递增栈
          int top = stk.top();
          stk.pop();
          //最大面积等于当前柱子高度乘以栈顶元素的下标减去栈顶下一个元素的下标
          //右边沿：正好是i（由于单调栈的性质，第i个柱子就是右边第一个矮于A的柱子）
          //左边沿：单调栈中紧邻A的柱子。（如果A已经出栈，那么左边沿就是A出栈后的栈顶）而且是该柱子的右边，所以要+1.
          //当A出栈后，单调栈为空时，那就是说明，A的左边没有比它矮的。左边沿就可以到0.
          maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
        }
        stk.push(i);
      }
      return maxArea;
    }
};
int main() {
  vector<int> test = {2, 1, 5, 6, 2, 3};
  int res = largestRectangleArea(test);
  return 0;
}
