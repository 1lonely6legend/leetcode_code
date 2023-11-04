//
// Created by ogier on 2023/11/4.
// 150.逆波兰表达式求值
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
 public:
	int evalRPN(vector<string> &tokens) {
		int res;
		stack<int> stk;
		for (string c : tokens) {
			if (c == "+" || c == "-" || c == "*" || c == "/") {
				switch (c[0]) {
					case '+': res = stk.top();
						stk.pop();
						res += stk.top();
						stk.pop();
						stk.push(res);
						break;
					case '-': res = stk.top();
						stk.pop();
						res = stk.top() - res;
						stk.pop();
						stk.push(res);
						break;
					case '*': res = stk.top();
						stk.pop();
						res *= stk.top();
						stk.pop();
						stk.push(res);
						break;
					case '/': res = stk.top();
						stk.pop();
						res = stk.top() / res;
						stk.pop();
						stk.push(res);
						break;
				}
			} else {
				stk.push(stoi(c));
			}
		}
		return stk.top();
	}
};