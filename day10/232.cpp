//
// Created by ogier on 2023/11/3.
// 232.用栈实现队列
#include <stack>
using namespace std;
class MyQueue {
 private:
	stack<int> sin;
	stack<int> sout;
 public:
	MyQueue() {

	}

	void push(int x) {
		sin.push(x);
	}

	int pop() {
		if (sout.empty()) {
			while (!sin.empty()) {
				sout.push(sin.top());
				sin.pop();
			}
		}
		int tmp = sout.top();
		sout.pop();
		return tmp;
	}

	int peek() {
		if (sout.empty()) {
			while (!sin.empty()) {
				sout.push(sin.top());
				sin.pop();
			}
		}

		return sout.top();
	}

	bool empty() {
		return sin.empty() && sout.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */