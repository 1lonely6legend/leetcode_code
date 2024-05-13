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
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        int x = nums[i]-1;
        swap(nums[x], nums[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};

int main() {
  vector<int> test = {3, 4, -1, 1};
  Solution S;
  int res = S.firstMissingPositive(test);
  return 0;
}