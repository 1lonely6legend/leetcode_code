//
// Created by ogier on 2023/11/6.
// 239.滑动窗口最大值
// 自己没做出来
// 关键点是维护一个单调递减的队列
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Solution {
 private:
	class Myqueue {//单调队列，从大到小
	 public:
		deque<int> que;
		void pop(int value) {
			if (!que.empty() && value == que.front()) {
				que.pop_front();
			}
		}
		void push(int value) {
			while (!que.empty() && value > que.back()) {
				que.pop_back();
			}
			que.push_back(value);
		}
		int front() {
			return que.front();
		}
	};
 public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		Myqueue que;
		vector<int> res;
		for (int i = 0; i < k; ++i) {
			que.push(nums[i]);
		}
		res.emplace_back(que.front());
		for (int i = k; i < nums.size(); ++i) {
			que.pop(nums[i-k]);//挺关键的，移除这个元素，但这时候不一定在队列中
			que.push(nums[i]);
			res.emplace_back(que.front());
		}
		return res;
	}
};