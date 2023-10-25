//
// Created by ogier on 2023/10/25.
//
#include <iostream>
#include <vector>
using std::vector;

class Solution {
 public:
	int removeElement(vector<int> &nums, int val) {
		int slow = 0;
		for (int fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != val)
				nums[slow++] = nums[fast];
		}
		return slow;
	}
};

int main() {

	return 0;
}