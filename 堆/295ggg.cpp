//
// Created by ogier on 24-5-25.
//
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class MedianFinder {
public:
  MedianFinder() {
  }
  void addNum(int num) {//如果两个堆大小相等了,我选择将新的数放到大顶堆,也就是更小的一组数中
    if (max_heap_.size() == min_heap_.size()) {
      //如果两个堆的大小相等，先插入到小顶堆，再将小顶堆的堆顶元素插入到大顶堆
      min_heap_.emplace(num);
      max_heap_.push(min_heap_.top());
      min_heap_.pop();
    } else {
      //如果两个堆的大小不相等，根据上面情况，此时小顶堆多一个数字，所以这个元素要放到大顶堆中
      max_heap_.push(num);
      min_heap_.push(max_heap_.top());
      max_heap_.pop();
    }
  }
  double findMedian() {
    //这里对于min_heap_可能会空的情况，但是由于至少会放一个数，max_heap_不会为空
    //如果二者大小相等，那么肯定有两个数及以上，所以不用担心min_heap_为空的情况，直接返回平均值
    //如果二者大小不等，那么肯定有一个数，所以直接返回max_heap_的堆顶元素，也不用考虑min_heap_为空的情况
    return max_heap_.size() == min_heap_.size() ? (max_heap_.top() + min_heap_.top()) / 2.0 : max_heap_.top();
  }
private:
  //选择使用两个堆，一个大顶堆，一个小顶堆,大顶堆存放较小的一半，小顶堆存放较大的一半
  priority_queue<int, vector<int>> max_heap_;
  priority_queue<int, vector<int>, greater<int>> min_heap_;
};
int main() {
  MedianFinder mf;
  mf.addNum(1);
  double res1 = mf.findMedian();
  mf.addNum(3);
  double res2 = mf.findMedian();
  return 0;
}
