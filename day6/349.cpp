//
// Created by ogier on 2023/10/29.
// 349.两个数组的交集

//我选择使用一个map记录出现次数
//也可以使用两个set来二次过滤重复数字

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		unordered_map<int, int> map;
		vector<int> res;
		for (auto num : nums1)
			map[num] = 0;
		for (auto num : nums2) {
			if (map.find(num) != map.end() && map[num] == 0){
				res.emplace_back(num);
				map[num]++;
			}
		}
		return res;
	}
};