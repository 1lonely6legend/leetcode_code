//
// Created by ogier on 24-5-13.
//
#include <stack>
#include <climits>
using namespace std;
class MinStack {
  public:
    MinStack() {
      min_stack.push(INT_MAX);
    }

    void push(int val) {
      x_stack.emplace(val);
      min_stack.push(min(val, min_stack.top()));
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

  private:
    stack<int> x_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//只是用一个数组的情况
class MinStack2 {
  public:
  stack<long> dist;
  long min_s;
  MinStack2() : min_s(0) {}

  void push(int val) {
    if (dist.empty()) {
      min_s = val;
      dist.push(0);
    } else {
      long diff = val - min_s;
      dist.push(diff);
      min_s = diff > 0 ? min_s : val;
    }
  }

  void pop() {
    if (!dist.empty()) {
      long diff = dist.top();
      dist.pop();
      min_s = diff > 0 ? min_s : min_s - diff;
    }
  }

  int top() {
    if (dist.empty()) {
      return -1;
    } else {
      long diff = dist.top();
      if (diff > 0) {
        return (diff + min_s);
      } else {
        return min_s;
      }
    }
  }

  int getMin() {
    if (dist.empty()) {
      return -1;
    } else {
      return min_s;
    }
  }
};