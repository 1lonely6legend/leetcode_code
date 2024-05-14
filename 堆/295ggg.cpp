//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class MedianFinder {
  public:
    priority_queue<int, vector<int>, greater<int> > A;//小顶堆，保存较大的数据，这样浮出的为中间值
    priority_queue<int, vector<int>, less<int> > B;//小顶堆，保存较大的数据，这样浮出的为中间值
    MedianFinder() {
    }
    void addNum(int num) {
      //为了保证始终A中放大数，B中放小数，所以当A.size()!=B.size()时，先放入A中，再将A中的最小值放入B中，反之亦然
      //相当于把两个堆当做一个过滤器，保证了A中的数始终大于B中的数
      if (A.size()!=B.size()) {
        //两个大小不等，结果要放入b中，但首先经过A过滤，保证b中的数始终小于A中的数
        A.push(num);
        B.push(A.top());
        A.pop();
      }else {
        //两个大小相等，结果要放入A中，但首先经过B过滤，保证A中的数始终大于B中的数
        B.push(num);
        A.push(B.top());
        B.pop();
      }
    }

    double findMedian() {
      return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
