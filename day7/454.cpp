//
// Created by ogier on 2023/10/31.
// 454.四数相加Ⅱ

//我这个真的好慢
// 其实不需要第二个map，直接遍历后两组的时候在第一个map上找就行
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
		int res = 0;
		unordered_map<long, int> map1;
		unordered_map<long, int> map2;
		//因为是遍历两个数组，不会出现重复的问题
		for (int numa : nums1) {
			for (int numb : nums2) {
				map1[numa + numb]++;
			}
		}
		for (int numa : nums3) {
			for (int numb : nums4) {
				map2[numa + numb]++;
			}
		}
		for (auto a : map1) {
			for (auto b : map2) {
				if (a.first + b.first == 0)
					res += a.second* b.second;
			}
		}
		return res;
	}
};