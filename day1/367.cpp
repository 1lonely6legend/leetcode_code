//
// Created by ogier on 2023/10/26.
// 367.有效的完全平方数

//二分法，以及需要使用long防止超过int表示长度

#include <iostream>
#include <vector>
using std::vector;

class Solution {
 public:
	bool isPerfectSquare(int num) {
		int left = 0;
		int right = num;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			long square = (long)mid * mid;
			if (square < num) {
				left = mid + 1;
			} else if (square > num) {
				right = mid - 1;
			} else if (square == num) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution S;
	std::cout << S.isPerfectSquare(16);
	return 0;
}
