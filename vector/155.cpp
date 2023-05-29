//
// Created by ogier on 2023/5/29.
// 155. 最小栈
#include <iostream>
#include <stack>
using std::stack;
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
  stack<int> x_stack;
  stack<int> min_stack;
 public:
  MinStack() {
    min_stack.push(INT_MAX);
  }

  void push(int x) {
    x_stack.push(x);
    min_stack.push(std::min(min_stack.top(), x));
  }

  void pop() {
    x_stack.pop();
    min_stack.pop();
  }

  int top() {
    return x_stack.top();
  }

  int getMin() {
    return min_stack.top();
  }
};