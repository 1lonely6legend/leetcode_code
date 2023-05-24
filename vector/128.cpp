//
// Created by ogier on 2023/5/24.
// 128. 最长连续序列
// 注意考虑一个相同数字多次出现的情况
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

int longestConsecutive(vector<int> &nums) {
  //首先判断数组长度为0/1的时候,直接返回
  int size = nums.size();
  if (size == 0 || size == 1)
    return size;

  //把答案数组初始化为0,方便后续取大
  int res = 0;
  int i = 0;
  //对数组进行排序
  std::sort(nums.begin(), nums.end());
  //对数组进行遍历
  while (i < size) {
    //记录当前这次遍历的最长的长度,保底最少也有1长度的是连续的,
    int temp = 1;
    //检查连续的数组长促进行遍历
    while (i + 1 < size) {
      if (nums[i + 1] == nums[i] + 1) {
        //如果数字是连续的,继续向后看,并且长度temp加一
        ++i;
        temp++;
      } else if (nums[i + 1] == nums[i]) {
        //注意考虑这种有相同数字多次出现的情况,这种只需要继续遍历,而最长长度temp不变
        ++i;
      } else {
        //说明数字不连续也不相同了,直接退出循环,寻找下一个连续的数组
        break;
      }
    }
    //最后退出的时候i还是上一个连续数组的最后一个值,所以++i
    ++i;
    //答案要取历次遍历连续数组中的最大值
    res = std::max(temp, res);
  }
  return res;
}

int main() {
  vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
  std::cout << longestConsecutive(nums);
  return 0;
}