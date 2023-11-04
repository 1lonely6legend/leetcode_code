//
// Created by ogier on 2023/11/4.
// 20.有效的括号
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
 public:
	bool isValid(string s) {
		stack<char> stk;
		for (char c : s) {
			if (c == '(' || c == '{' || c == '[')
				stk.push(c);
			if (c == ')') {
				if (stk.empty() || stk.top() != '(') {
					return false;
				} else {
					stk.pop();
					continue;
				}
			}
			if (c == '}') {
				if (stk.empty() || stk.top() != '{') {
					return false;
				} else {
					stk.pop();
					continue;
				}
			}
			if (c == ']') {
				if (stk.empty() || stk.top() != '[') {
					return false;
				} else {
					stk.pop();
					continue;
				}
			}
		}
		if (stk.empty())return true;
		return false;
	}
};