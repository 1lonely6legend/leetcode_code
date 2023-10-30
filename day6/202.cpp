//
// Created by ogier on 2023/10/29.
// 202.快乐数

//这个还是有点麻烦的，
// 一是取各个位数
// 二是while循环中，sum，n等变量的更新位置，return结果的条件

#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
	bool isHappy(int n) {
		unordered_set<int> set;

		while (true) {
			long sum = 0;
			while (n != 0) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			n = sum;
			if (sum == 1)return true;
			if (set.find(n) != set.end()) {
				return false;
			} else {
				set.emplace(n);
			}
		}
	}
};