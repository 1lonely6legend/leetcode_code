//
// Created by ogier on 2023/5/29.
// 150. 逆波兰表达式求值
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
using std::string;
using std::vector;
using std::stack;

bool isNumber(string& token) {
  return !(token == "+" || token == "-" || token == "*" || token == "/");
}
int evalRPN(vector<string>& tokens) {
  stack<int> stk;
  int n = tokens.size();
  for (int i = 0; i < n; i++) {
    string& token = tokens[i];
    if (isNumber(token)) {
      stk.push(atoi(token.c_str()));
    } else {
      int num2 = stk.top();
      stk.pop();
      int num1 = stk.top();
      stk.pop();
      switch (token[0]) {
        case '+':
          stk.push(num1 + num2);
          break;
        case '-':
          stk.push(num1 - num2);
          break;
        case '*':
          stk.push(num1 * num2);
          break;
        case '/':
          stk.push(num1 / num2);
          break;
      }
    }
  }
  return stk.top();
}



int main() {
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  std::cout << evalRPN(tokens) << std::endl;
  return 0;
}