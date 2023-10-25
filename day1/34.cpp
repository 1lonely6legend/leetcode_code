//
// Created by ogier on 2023/10/25.
// 34在排序数组中查找元素的第一个和最后一个位置

//在判断数组越界这种问题上，要把判断越界放在&&的前边，首先判断是否越界

#include <iostream>
#include <vector>
using std::vector;

class Solution {
 public:
	vector<int> searchRange(vector<int> &nums, int target) {
		vector<int> res;
		int left = 0;
		int size = nums.size();
		int right = size - 1;
		while (left <= right) {
			int mid = left + (right - left);
			if (nums[mid] < target) {
				left = right + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else if (nums[mid] == target) {
				int left_point = mid;
				int right_point = mid;
				std::cout << mid << std::endl;
				while (left_point - 1 >= 0 && nums.at(left_point - 1) == target) {
					left_point--;
				}
				while (right_point + 1 < size && nums.at(right_point - 1) == target) {
					right_point++;
				}
				return {left_point, right_point};
			}
		}
		return {-1, -1};
	}
};

int main() {
	vector<int> test = {1};
	Solution S;
	auto res = S.searchRange(test, 1);
	return 0;
}
