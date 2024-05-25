//
// Created by ogier on 24-5-14.
//https://blog.csdn.net/Zolewit/article/details/88863970
#include <stack>
#include <climits>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
//说白了，这题考的基础模型其实就是：在一维数组中对每一个数找到第一个比自己小的元素。
//这类“在一维数组中找第一个满足某种条件的数”的场景就是典型的单调栈应用场景
class Solution {
  //对数组中的每个元素，若假定以它为高，能够展开的宽度越宽，那么以它为高的矩形面积就越大。
  //因此，思路就是找到每个元素左边第一个比它矮的矩形和右边第一个比它矮的矩形，在这中间的就是最大宽度
  //最后对每个元素遍历一遍找到最大值即可。
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    stack<int> stk;
    int res = 0;
    for(int i = 0; i < heights.size(); ++i) {
      while(!stk.empty() && heights[i] < heights[stk.top()]) {
        //一个单调递增栈，栈中存放的是柱子的下标
        int tmp = stk.top();
        stk.pop();
        //怎么说呢，就是当这个数递增时，我们不去计算最大值，因为大肯定还在后面
        //当前这个数小于栈顶元素时，我们就可以计算了，因为这个数是短板因为肯定比栈顶元素小
        //所以我们可以计算以栈顶元素为高度的矩形的最大面积
        //再弹出之后，如果栈为空，说明这个数是最小的，所以宽度就是i
        //如果栈不为空，那么宽度就是i - 栈顶元素 - 1
        res = max(res,heights[tmp] * (stk.empty()? i : (i - stk.top() - 1)));
      }
      stk.push(i);
    }
    return res;
  }
};
int main() {
  vector<int> test = {2, 1, 5, 6, 2, 3};
  int res = largestRectangleArea(test);
  return 0;
}
