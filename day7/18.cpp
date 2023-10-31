//
// Created by ogier on 2023/10/31.
// 18.四数之和

//注意这道题数组的最小长度是1
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
 public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; ++i) {
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			for (int j = i + 1; j < nums.size() - 2; ++j) {
				if (j > i + 1 && nums[j - 1] == nums[j])
					continue;
				int left = j + 1;
				int right = nums.size() - 1;
				while (left < right) {
					long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back({nums[i], nums[j], nums[left], nums[right]});
						while (left < right && nums[left] == nums[left + 1])
							left++;
						while (left < right && nums[right - 1] == nums[right])
							right--;
						left++;
						right--;
					} else if (sum < target) {
						left++;
					} else {
						right--;
					}
				}
			}
		}
		return res;
	}
};