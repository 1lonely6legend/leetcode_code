//
// Created by ogier on 2023/4/28.
// 274 H指数
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int hIndex(vector<int> &citations) {
  std::sort(citations.begin(), citations.end());
  if (*(citations.end() - 1) == 0) return 0;
  int size = citations.size();
  int num = size;
  int i = 0;
  while (i < size) {
    if (citations[i] >= num) break;
    --num;
    ++i;
  }
  if (citations.at(i) == num) return citations[i];
  else return num;
}

int main() {
  vector<int> nums = {0,1,3,1};
  std::cout << hIndex(nums);
  return 0;
}