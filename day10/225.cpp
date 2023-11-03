//
// Created by ogier on 2023/11/3.
// 225.用队列实现栈
#include <queue>
using namespace std;
class MyStack {
 private:
	queue<int> q1;
	queue<int> q2;
 public:
	MyStack() {
	}
	void push(int x) {
		q1.push(x);
	}
	int pop() {
		while (q1.size() > 1) {
			int tmp = q1.front();
			q1.pop();
			q2.push(tmp);
		}
		int tmp = q1.front();
		q1.pop();
		while (!q2.empty()) {
			int tmp = q2.front();
			q2.pop();
			q1.push(tmp);
		}
		return tmp;
	}

	int top() {
		return q1.back();
	}

	bool empty() {
		return q1.empty() && q2.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	MyStack M;
	M.push(1);
	M.push(2);
	int res1 = M.top();
	int res2 = M.pop();
	bool res3 = M.empty();
	return 0;
}