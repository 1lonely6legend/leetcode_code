//
// Created by ogier on 24-5-14.
//
#include <functional>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  void maxHeapify(vector<int> &a, int i, int heapSize) {
    //定义要比较的点,左右孩子
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;
    if (l < heapSize && a[l] > a[largest]) {
      largest = l;//如果左孩子大于根节点，将左孩子的下标赋值给largest
    }
    if (r < heapSize && a[r] > a[largest]) {
      largest = r;//如果右孩子大于根节点，将右孩子的下标赋值给largest
    }
    if (largest != i) {
      //需要交换,交换后递归调用maxHeapify维护
      swap(a[i], a[largest]);
      maxHeapify(a, largest, heapSize);
    }
  }

  void buildMaxHeap(vector<int> &a, int heapSize) {
    for (int i = heapSize / 2; i >= 0; --i) {
      //从最后一个非叶子节点(最后一个点的父节点)开始，自底向上构建最大堆,
      //最后一个节点的下标为n-1,则最后一个非叶子节点的下标为(n-1-1)/2 = n/2-1
      maxHeapify(a, i, heapSize);//对每一个非叶子节点调用maxHeapify
    }
  }

  int findKthLargest(vector<int> &nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);//构建最大堆
    //从最后一个节点开始，每次将堆顶元素与最后一个元素交换，然后维护堆的性质
    //这样只需要进行k-1次即可找到第k大的元素,因为前k-1个元素都是最大的
    for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
      swap(nums[0], nums[i]);
      --heapSize;
      //维护堆的性质,这里用了个堆排序,每次将最大的元素放到最后
      maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
  }
};
class SolutionQsort {
 public:
  int Qsort(vector<int> &nums, int begin, int end, int k) {
    if (begin >= end) return nums[k];
    int left = begin, right = end, key = nums[begin];
    while (left < right) {
      while (left < right && nums[right] >= key) right--;
      nums[left] = nums[right];
      while (left < right && nums[left] <= key) left++;
      nums[right] = nums[left];
    }
    nums[left] = key;
    if (k <= left)//如果k在排好的位置的左边，直接对左边进行排序，否则对右边进行排序
      return Qsort(nums, begin, left - 1, k);
    else
      return Qsort(nums, left + 1, end, k);
  }
  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    return Qsort(nums, 0, n - 1, n - k);
  }
};
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
      pq.emplace(num);
      while (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};
int main() {
  vector<int> test = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  SolutionQsort S;
  int res = S.findKthLargest(test, 2);
  return 0;
}
