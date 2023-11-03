//
// Created by ogier on 2023/11/2.
// 459.重复的子字符串
// 最好的答案肯定是KMP
#include <string>
using namespace std;
class Solution {
 public:
	bool repeatedSubstringPattern(string s) {
		return (s + s).find(s, 1) != s.size();
	}
};

int main() {
	string s1 = "abcabc";
	Solution S;
	int res = S.repeatedSubstringPattern(s1);
	return 0;
}