//
// Created by ogier on 2022/11/23.
//

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int findrepeat(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end()) {
            return nums[i];
        }
        map[nums[i]] = 1;
    }
    return -1;
}

int main() {
  vector<int> nums = {2, 3, 1, 1, 0, 2, 5, 3};
  cout << findRepeatNumber(nums) << endl;
  return 0;
}