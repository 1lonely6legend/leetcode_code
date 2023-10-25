//
// Created by ogier on 2023/10/25.
// 35.搜索插入位置

#include <iostream>
#include <vector>
using std::vector;

class Solution {
 public:
	int searchInsert(vector<int> &nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) { //注意这里的判断条件
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else if (nums[mid] == target) {
				return mid;
			}
		}
		return right+1;
	}
};