//
// Created by ogier on 2023/11/2.
// 28.找出字符串中第一个匹配项的下标
#include <string>
using namespace std;
class Solution {
 public:
	int strStr(string haystack, string needle) {
		int size1 = haystack.size();
		int size2 = needle.size();
		if (size2 > size1) return -1;
		//注意如果size相同会直接退出，注意判断退出条件，需要再加一
		for (int i = 0; i < size1 - size2+1; ++i) {
			/*
			第一个pos
			Index of first character (default 0).
			第二个是n，不是结束的索引
			Number of characters in substring (default remainder)
			 */
			string tmp = haystack.substr(i, size2);
			if (tmp == needle)
				return i;
		}
		return -1;
	}
};

int main() {
	string s1 = "abc";
	string s2 = "c";
	Solution S;
	int res = S.strStr(s1, s2);
	return 0;
}