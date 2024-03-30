//
// Created by ogier on 24-3-30.
//
#include <vector>
#include <stack>
using namespace std;
class SolutionDP {
 public:
  int trap(vector<int> &height) {
    int n = height.size();
    if (n == 0)
      return 0;

    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
      res += min(leftMax[i], rightMax[i]) - height[i];
    }
    return res;
  }
};

class SolutionStack {
 public:
  int trap(vector<int> &height) {
    int res = 0;
    stack<int> stk;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        //单调栈不空，并且当前的值比栈顶元素大，下面查看能否接雨水
        int top = stk.top();
        stk.pop();
        if (stk.empty())
          //这里说明栈中只有top一个元素，这样无法接雨水，将当前更大的值压入栈中，直接break
          break;
        //此时栈中仍有元素，可以存储雨水
        int left = stk.top();
        int currWidth = i - left - 1;
        //这里的高度， 算的是雨水的高度
        int currHeight = min(height[left], height[i] - height[top]);
        res += currHeight * currWidth;
      }
      stk.push(i);
    }
    return res;
  }
};


/*
对于下标i位置的储水量，我们要知道它对应的左右两边柱子的高度，储水量就是由其中低的一方决定，另一边再高也不会产生影响，即

    Math.min(leftHeight, rightHeight) - height[i]
这里说的左右柱子又是什么呢？就是以i为中心，向左边遍历能找到的最大值，同理，向右边遍历找到的最大值，就是右边的柱子高度

    我们维护两个指针left和right，分别从height数组的最左边和最右边开始遍历，维护
    maxHeightLeft和maxHeightRight表示左右两边柱子的最大值，每次都分别和left/right对应的高度比较，遇到更高的就更新

    当maxHeightLeft < maxHeightRight时，左边left指针对应位置的储水量就能确定，因为此时maxHeightLeft是left指针往左能找到的最大值，也就是左边柱子高度，而同时右边的柱子有比它高的，所以储水量由当前左边柱子决定
    同理，当maxHeightLeft > maxHeightRight，右边right指针对应位置的储水量也能确定，因为此时maxHeightRight是right指针往右能找到的最大值，而左边的柱子有比它高的，所以储水量由当前右边柱子决定

*/

class Solution2Point {
 public:
  int trap(vector<int> &height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
      leftMax = max(leftMax, height[left]);
      rightMax = max(rightMax, height[right]);
      if (height[left] < height[right]) {
        res += leftMax - height[left];
        ++left;
      } else {
        res += rightMax - height[right];
        --right;
      }
    }
    return res;
  }
};

int main() {
  Solution2Point C;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto res = C.trap(height);
  return 0;
}