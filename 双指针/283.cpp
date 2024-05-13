//
// Created by ogier on 24-5-13.
//
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0)
        nums[index++] = nums[i];
    }
    for (int i = index; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};

int main() {
  vector<int> test = {0, 1, 0, 3, 12};
  Solution S;
  S.moveZeroes(test);
  return 0;
}