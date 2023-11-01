//
// Created by ogier on 2023/11/1.
// 344.反转字符串

#include <string>
#include<vector>
using namespace std;

class Solution {
 public:
	void reverseString(vector<char> &s) {
		for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
			int tmp = s[j];
			s[j] = s[i];
			s[i] = tmp;
		}
	}
};