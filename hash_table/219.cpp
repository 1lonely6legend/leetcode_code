//
// Created by ogier on 2023/4/20.
// 219. 存在重复元素 II
// https://leetcode.cn/problems/contains-duplicate-ii
// 就是找nums中是否有两个相同的元素间距小于k的
// 我使用的hashmap,还有空间复杂度更低的滑动窗口
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;
using std::vector;


//hashmap
bool containsNearbyDuplicate(vector<int> &nums, int k) {
  unordered_map<int, int> map;//初始化map
  for (int i = 0; i < nums.size(); ++i) {//遍历nums,
    // *****这种每次到循环最后才把当前值插入map,防止自己查找自己*****
    if (map.find(nums[i]) == map.end()) {//如果没有找到,插入当前值
      map[nums[i]] = i;
      continue;//直接下次循环
    }
    //如果能到这里,说明在之前有当前值
    if ((i - map.find(nums[i])->second) <= k)//如果距离小于k,返回
      return true;
    map[nums[i]] = i;//最后记得如果距离果园不符合要求,还需要插入当前值
  }
  return false;
}

//滑动窗口
//只用hashmap存储滑动窗口范围内的数据
/*bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_set<int> s;//使用unordered_set只存储key
  int length = nums.size();
  for (int i = 0; i < length; i++) {//遍历nums
    if (i > k) {//说明现在map长度已经超过k,需要删除最前的值
      s.erase(nums[i - k - 1]);
    }
    //如果在这个窗口内可以找到nums[i],返回true,(此时当前位置的nums[i]还没有存进unordered_set中)
    if (s.count(nums[i])) {
      return true;
    }
    s.emplace(nums[i]);//如果什么特殊情况都没有发生,就添加当前值
  }
  return false;
}*/

int main() {
  vector<int> nums = {1, 2, 3};
  int k = 2;
  bool ans = containsNearbyDuplicate(nums, k);
  std::cout << ans;
  return 0;
}
