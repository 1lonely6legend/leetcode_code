//
// Created by ogier on 2023/11/4.
// 1047.删除字符串中的左右相邻重复项
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Solution {
 public:
	string removeDuplicates(string s) {
		stack<char> stk;
		for (auto c : s) {
			if (!stk.empty()) {
				if (c == stk.top()) {
					stk.pop();
					continue;
				}
			}
			stk.push(c);
		}
		s.resize(stk.size());
		for (int i = 0; i < s.size(); ++i) {
			s[i] = stk.top();
			stk.pop();
		}
		for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
			char tmp;
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
		return s;
	}
};