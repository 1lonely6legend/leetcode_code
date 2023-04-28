// 参考55跳跃游戏1
// Created by ogier on 2023/4/27.
// 45. 跳跃游戏 II
// 这次题目中给的一定可以跳到最后一个位置，找最少的跳跃次数
// tnnd依旧是没有做出来，看答案https://leetcode.cn/problems/jump-game-ii/solution/45-by-ikaruga/
#include <iostream>
#include <vector>

using std::vector;

int jump(vector<int> &nums) {
  int ans = 0;//最少需要的跳跃次数
  int begin = 0;//每次遍历循环的起点
  int end = 0;//每轮遍历的终点
  //[begin, end]

  while (end < nums.size() - 1) {
    //不断在循环区间向前进，并更新最远的区间，直到到达包含最后一个元素的区间
    int temp = 0;//初始化临时变量
    for (int i = begin; i <= end; i++) {//在上次最远的运行区间内遍历所有
      temp = std::max(nums[i] + i, temp);//记录这个循环目前为止的最远距离
    }
    begin = end + 1;//进入下一个循环
    end = temp;
    ans++;
  }
  return ans;
}

int main() {
  auto nums = vector<int>({2, 3, 1, 1, 4});
  std::cout << jump(nums);
  return 0;
}

