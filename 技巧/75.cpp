//
// Created by ogier on 24-5-11.
//
#include <vector>

using namespace std;

class Solution {
 public://使用快速排序，时间复杂度O(nlogn)，空间复杂度O(1)，不如soulution1
  void qsort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, k = nums[left];
    while (i < j) {
      while (i < j && nums[j] >= k) --j;
      nums[i] = nums[j];
      while (i < j && nums[i] <= k) ++i;
      nums[j] = nums[i];
    }
    nums[i] = k;
    qsort(nums, left, i - 1);
    qsort(nums, i + 1, right);
  }

  void sortColors(vector<int> &nums) {
    qsort(nums, 0, nums.size() - 1);
  }
};

class Solution1 {
 public://双指针，因为只要三个数，所以只需要两个指针，把0放到前面，2放到后面，剩下的就是1
  void sortColors(vector<int>& nums) {
    int p0 = 0, p2 = nums.size() - 1;
    for (int i = 0; i <= p2; ++i) {
     //这里的i<=p2是因为p2是不断变化的，所以需要判断i是否超过p2
     //两个指针的移动是互斥的，所以不需要判断i是否超过p0
      while (i <= p2 && nums[i] == 2) {
        swap(nums[i], nums[p2--]);
      }
      if (nums[i] == 0) {
        swap(nums[i], nums[p0++]);
      }
    }
  }
};