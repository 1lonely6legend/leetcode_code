//
// Created by ogier on 24-5-11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] >= nums[0]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    //本题中可能会出现n个数旋转n次，也就是整体还是一个递增的结果，这个时候l最后会等于n，需要进行判断
    if (l == n) return nums[0];
    return min(nums[l], nums[0]);
  }
};

int main() {
  vector<int> test = {11, 13, 15, 17};
  Solution s;
  auto res = s.findMin(test);
  cout << res << endl;
  return 0;
}