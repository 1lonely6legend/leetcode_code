//
// Created by ogier on 24-5-11.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    int fast = 0, slow = 0;
    do {//
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (fast != slow);
    int entry = 0;
    while (entry != slow) {
      slow = nums[slow];
      entry = nums[entry];
    }
    return entry;
  }
};