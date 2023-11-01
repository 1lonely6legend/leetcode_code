//
// Created by ogier on 2023/11/1.
// 541.反转字符串Ⅱ
#include <string>
using namespace std;

class Solution {
 public:
	string reverseStr(string s, int k) {
		int start = 0;
		int size = s.length();
		while (start < size) {
			if (start + k < size)
				reverse(s, start, start + k-1);
			else
				reverse(s, start, size - 1);
			start += 2 * k;
		}
		return s;
	}
	void reverse(string& s, int left, int right) {
		for (int i = left, j = right; i < left+((right+1 - left)/ 2); ++i, --j) {
			swap(s[i], s[j]);
		}
	}
};

int main() {
	string test = "asdfgh";
	Solution S;
	string res = S.reverseStr(test, 2);
	return 0;
}