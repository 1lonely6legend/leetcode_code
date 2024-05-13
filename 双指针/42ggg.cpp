//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

//每个柱子能盛水的深度，取决于min(左边最高，右边最高)关键是理解这句话
class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> right(n, 0);
    for (int m = height[n - 1], i = n - 2; i > 0; i--) {
      right[i] = m;
      m = std::max(m, height[i]);
    }
    int ans = 0;
    for (int m = height[0], i = 1; i + 1 < n; i++) {
      int h = std::min(m, right[i]);
      if (h > height[i]) ans += (h - height[i]);
      m = std::max(m, height[i]);
    }
    return ans;
  }
};

//单调栈解法，时间空间复杂度都是o(n)
class Solution_stack {
 public:
  int trap(vector<int> &height) {
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        //使用这个比较的while循环，保证单调栈中的元素是递减的
        int mid = stk.top();
        stk.pop();
        if (stk.empty()) break;//如果栈为空，说明没有左边界，直接跳出循环
        int left = stk.top();
        int cur_width = i - left - 1;                               //计算宽度注意减1
        int cur_height = min(height[i], height[left]) - height[mid];//计算高度,这里需要减去mid的高度
        res += cur_height * cur_width;
      }
      stk.push(i);
    }
    return res;
  }
};

//双指针解法，时间复杂度o(n),空间复杂度o(1)
class Solution_double_pointer {
 public:
  int trap(vector<int> &height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;
    while (left < right) {
      left_max = max(left_max, height[left]);
      right_max = max(right, height[right]);
      if (height[left] < height[right]) {
        res += left_max - height[left];
        ++left;
      }else {
        res += right_max - height[right];
        --right;
      }
    }
    return res;
  }
};

int main() {
  vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution s;
  int res = s.trap(test);
  return 0;
}