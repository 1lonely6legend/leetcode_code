//
// Created by ogier on 2023/10/26.
// 209. 长度最小的子数组


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
// public:
//	int minSubArrayLen(int target, vector<int> &nums) {
//		int length = INT_MAX;
//		int sum = 0;
//		int left = 0;
//		int right = 0;
//		int size = nums.size();
//		for (; right < size; right++) {
//			sum += nums[right];
//			if (sum >= target) {
//				length = ((right - left + 1) < length) ? (right - left + 1) : length;
//				while (true) {
//					int temp = sum - nums[left];
//					if (temp < target)
//						break;
//					else {
//						sum = temp;
//						left++;
//						length = ((right - left + 1) < length) ? (right - left + 1) : length;
//					}
//				}
//			}
//		}
//		if (length == INT_MAX)
//			return 0;
//		else
//			return length;
//	}
//};

class Solution {
 public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int res = INT_MAX;
		int i = 0;
		int sum = 0;
		int sublength = 0;
		for (int j = 0; j < nums.size(); ++j) {
			sum += nums[j];
			while (sum >= target) {
				sublength = j - i + 1;
				res = sublength < res ? sublength : res;
				sum -= nums[i++];
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};

int main() {
	Solution S;
	vector<int> test = {2, 3, 1, 2, 4, 3};
	int res = S.minSubArrayLen(7, test);
	return 0;
}