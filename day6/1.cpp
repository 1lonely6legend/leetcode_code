//
// Created by ogier on 2023/10/29.
// 1.两数之和

//用map确实省事

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int>map;
		for (int i = 0; i < nums.size(); ++i) {
			//要注意map查找 要在 map插入这一步的前面，注意注意
			if(map.find(nums[i])!=map.end())
				return {i,map.find(nums[i])->second};
			map[target - nums[i]] = i;
		}
		return {};
	}
};

