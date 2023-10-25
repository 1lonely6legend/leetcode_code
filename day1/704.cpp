//
// Created by ogier on 2023/10/25.
//
#include <iostream>
#include <vector>
using std::vector;

//自己写的递归
/*class Solution {
 public:
	int search(vector<int> &nums, int target) {
		int num = nums.size();
		return search2(nums, 0, num - 1, target);
	}
 private:
	int search2(vector<int> &nums, int low, int high, int target) {
		if (low > high) return -1;
		int mid = low + (high - low) / 2;
		if (nums[mid] > target) return search2(nums, low, mid-1, target);
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) return search2(nums, mid+1, high, target);
		return false;
	}
};*/

//carl左闭右开二分法
class Solution {
 public:
	int search(vector<int> &nums, int target) {
		int left = 0;
		int right = nums.size();//左闭右开，所以不写-1
		while (left < right) {
			int middle = left + (right - left) >> 1;//直接位操作
			if (nums[middle] > target) {
				right = middle;
			} else if (nums[middle] == target) {
				return middle;
			} else if (nums[middle] < target) {
				left = middle + 1;
			}
		}
		return -1;
	}
};
int main() {

	return 0;
}