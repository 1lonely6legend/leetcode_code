//
// Created by ogier on 2023/4/11.
//
#include <vector>
#include <iostream>

using std::vector;

/*int removeDuplicates(vector<int> &nums) {
  int n = nums.size();
  if (n <= 2) {
    return n;
  }
  int slow = 2, fast = 2;
  while (fast < n) {
    if (nums[slow - 2] != nums[fast]) {
      nums[slow] = nums[fast];
      ++slow;
    }
    ++fast;
  }
  return slow;
}*/
int removeDuplicates(vector<int> &nums) {
  if (nums.size() <= 2) return nums.size();
  int index = 2;
  for (int i = 2; i < nums.size(); i++) {
    if (nums[i] != nums[index - 2])
      nums[index++] = nums[i];
  }
    return index;
}
int main() {
  vector<int> nums1 = {0, 0, 0, 0, 4, 4, 5};
  int ans = removeDuplicates(nums1);
  std::cout << ans;
  return 0;
}