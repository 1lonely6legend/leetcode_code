//
// Created by ogier on 24-5-11.
//
#include <vector>

using namespace std;

class Solution {
 public:
  void qsort(vector<int> &nums, int left, int right) {
    if (left >= right) return;//这里是大于等于，因为left==right的时候就不需要再进行排序了
    int l = left, r = right, key = nums[left];
    while (l < r) {//这里同样等于的时候也不需要再进行排序了
      while (l < r && nums[r] >= key) r--;//判断时等于时需要继续移动指针，因为key在左边
      nums[l] = nums[r];
      while (l < r && nums[l] <= key) l++;
      nums[r] = nums[l];
    }
    nums[l] = key;
    qsort(nums, left, l - 1);
    qsort(nums, l + 1, right);
  }

  int majorityElement(vector<int> &nums) {
    qsort(nums, 0, nums.size() - 1);
    return nums[nums.size() / 2];
  }
};

class Solution2 {
 public:
  int majorityElement(vector<int> &nums) {
    int res = 0, count = 0;//Boyer-Moore 算法，简单理解有一种消去数字的感觉，最后剩下的就是众数
    for (int num : nums) {
      if (count <= 0) {
        res = num;
        count = 1;
      } else if (num == res) {
        ++count;
      } else if (num != res) {
        --count;
      }
    }
    return res;
  }
};