//
// Created by ogier on 2023/4/28.
// 274 H指数
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int hIndex(vector<int>& citations) {
  std::sort(citations.begin(), citations.end());
  int h = 0, i = citations.size() - 1;
  while (i >= 0 && citations[i] > h) {
    h++;
    i--;
  }
  return h;
}

int main(){
  vector<int> nums = {3,0,6,1,5};
  std::cout<< hIndex(nums);
  return 0;
}