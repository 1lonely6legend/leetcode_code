//
// Created by ogier on 2024/4/6.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MyQueue de;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      de.push(nums[i]);
    }
    res.push_back(de.front());
    for (int i = k; i < nums.size(); ++i) {
      de.pop(nums[i - k]);
      de.push(nums[i]);
      res.push_back(de.front());
    }
    return res;
  }
 private:
  class MyQueue {
   public:
    deque<int> que;
    void pop(int val) {
      if (!que.empty() && val == que.front())
        que.pop_front();
    }
    void push(int val) {
      while (!que.empty() && val > que.back()) {
        que.pop_back();
      }
      que.push_back(val);
    }
    int front() {
      return que.front();
    }
  };
};

int main() {
  vector<int> test = {1, 3, 1, 2, 0, 5};
  Solution S;
  auto res = S.maxSlidingWindow(test, 3);
  return 0;
}