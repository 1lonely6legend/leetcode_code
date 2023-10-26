//
// Created by ogier on 2023/10/26.
//904.水果成篮

//总体上来说，就是在数组中寻找一段，最长的，且只包含两种数字。求这段数组的长度。一眼滑动窗口

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int totalFruit(vector<int> &fruits) {
		int size = fruits.size();
		// 设计一个哈希表，储存元素的个数,方便进行滑动窗口
		unordered_map<int, int> cnt;
		int left = 0, ans = 0;
		for (int right = 0; right < size; ++right) {
			++cnt[fruits[right]];
			while (cnt.size() > 2) {
				//这一步的意思是，当目前窗口元素种类大于2的时候：
				//1.确定当前窗口最左边的元素是哪个
				//2.不断向左移动窗口边界，直到排除掉这个元素（这里使用哈希表计数）
				auto it = cnt.find(fruits[left]);
				--it->second;
				if (it->second == 0) {
					cnt.erase(it);
				}
				++left;
			}
			ans = max(ans, right - left + 1);
		}
		return ans;
	}
};