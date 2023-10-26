//
// Created by ogier on 2023/10/26.
// 69 x的平方根

#include <iostream>
using namespace std;
class Solution {
 public:
	int mySqrt(int x) {
		int left = 0;
		int right = x;
		while (left <= right) {
			int mid = left + (right - left)/2;
			long square = (long)mid * mid;
			if (square > x) {
				right = mid - 1;
			} else if (square < x) {
				left = mid + 1;
			} else if (square == x) {
				return mid;
			}
		}
		return right;
	}
};

int main() {
	Solution S;
	int res = S.mySqrt(2147395599);
	return 0;
}