//
// Created by ogier on 2023/10/26.
// 977.有序数组的平方
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
	vector<int> sortedSquares(vector<int> &nums) {
		int left = 0;
		int right = nums.size() - 1;
		vector<int> res(0);
		while (left <= right) {
			if (abs(nums[right]) >= abs(nums[left])) {
				res.push_back(nums[right] * nums[right]);
				right--;
			} else {
				res.push_back(nums[left] * nums[left]);
				left++;
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution S;
	vector<int> test = {-7, -3, 2, 3, 11};
	vector<int> res = S.sortedSquares(test);
	return 0;
}
