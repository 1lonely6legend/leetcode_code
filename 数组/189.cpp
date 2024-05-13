//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  void rotate_part(vector<int> &nums, int begin, int end) {
    while (begin < end) {
      swap(nums[begin++], nums[end--]);
    }
  }
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    rotate_part(nums, 0, nums.size() - 1);
    rotate_part(nums, 0, k - 1);
    rotate_part(nums, k, nums.size() - 1);
  }
};

int main() {
  vector<int> test = {1,2,3,4,5,6,7};
  Solution S;
  S.rotate(test, 2355);
  return 0;
}