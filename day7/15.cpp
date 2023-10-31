//
// Created by ogier on 2023/10/31.
// 15.三数之和
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
//要特别注意的是遍历时产生的重复数组不算数

//md遍历到第三个数字时我去搞二分查找了，整了半天没做出来，下面是cgatgpt在我上面改的
class Solution {
 public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;
					left++;
					right--;
				} else if (sum < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		return res;
	}
};

int main() {
	vector<int> test = {{-1, 0, 1, 2, -1, -4}};
	Solution S;
	vector<vector<int>> res = S.threeSum(test);

	return 0;
}

