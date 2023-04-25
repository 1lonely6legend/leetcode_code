//
// Created by ogier on 2023/4/21.
// 228. 汇总区间
// 使用反斜杠来添加\"字符

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

vector<string> summaryRanges(vector<int> &nums) {
  vector<string> res;
  int i = 0;
  int n = nums.size();
  while (i < n) {
    string str;
    str += std::to_string(nums[i]);//每个区间一开始第一个数肯定是要进去的
    int j = i + 1;
    //下面判断循环时,首先判j<n防止溢出
    while (j < n && nums[j] == nums[j - 1] + 1)//判断这个区间能有多连续
      ++j;
    if (j != i + 1) {//如果j!=i+1,说明这个区间不止一个数
      str += "->";
      str += std::to_string(nums[j - 1]);
    }
    i = j;
    res.push_back(str);
  }
  return res;
}

int main() {
  vector<int> nums = {0, 1};
  vector<string> ans = summaryRanges(nums);
  for (auto s : ans) {
    std::cout << s << ' ';
  }
  return 0;
}
