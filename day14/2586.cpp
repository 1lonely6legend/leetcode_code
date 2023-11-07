//
// Created by ogier on 2023/11/7.
// 2586. 统计范围内的元音字符串数
#include<vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 public:
	int vowelStrings(vector<string> &words, int left, int right) {
		int res = 0;
		unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
		for (int i = left; i <= right; ++i) {
			string tmp = words[i];
			if (set.count(tmp[0]) && set.count(tmp.back()))
				res++;
		}
		return res;
	}
};