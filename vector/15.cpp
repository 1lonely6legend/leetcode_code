//
// Created by ogier on 2023/5/15.
// 15. 三数之和
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;

vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size();
  //首先进行排序
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  // 枚举 a
  for (int first = 0; first < n; ++first) {
    // 需要和上一次枚举的数不相同
    if (first > 0 && nums[first] == nums[first - 1]) {
      continue;
    }
    // c 对应的指针初始指向数组的最右端
    int third = n - 1;
    int target = -nums[first];
    // 枚举 b
    // 类似利用167,两数之和的方法进行查找
    for (int second = first + 1; second < n; ++second) {
      // 需要和上一次枚举的数不相同
      if (second > first + 1 && nums[second] == nums[second - 1]) {
        continue;
      }
      // 需要保证 b 的指针在 c 的指针的左侧
      while (second < third && nums[second] + nums[third] > target) {
        --third;
      }
      // 如果指针重合，随着 b 后续的增加
      // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
      if (second == third) {
        break;
      }
      if (nums[second] + nums[third] == target) {
        ans.push_back({nums[first], nums[second], nums[third]});
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto ans = threeSum(nums);
  return 0;
}
