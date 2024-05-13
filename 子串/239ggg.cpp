//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    int n = nums.size();
    priority_queue<pair<int, int>> pq;//声明一个优先队列，队列中的元素是pair<int,int>类型，第一个元素是数组中的元素，第二个元素是元素的下标
    //将数组中的前k个元素加入到优先队列中,优先队列默认是大顶堆
    for (int i = 0; i < k; ++i) {
      pq.emplace(nums[i], i);
    }
    //记得初始化之后将第一个窗口的最大值加入到结果数组中
    res.emplace_back(pq.top().first);
    for (int i = k; i < nums.size(); ++i) {
      //将新的元素加入到优先队列中
      pq.emplace(nums[i], i);
      //这个循环是为了保证优先队列中的元素是在窗口范围内的,只需要保证堆顶元素的下标在窗口范围内即可
      while (pq.top().second <= i - k) {
        pq.pop();
      }
      //将堆顶元素加入到结果数组中
      res.emplace_back(pq.top().first);
    }
    return res;
  }
};