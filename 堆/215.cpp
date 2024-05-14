//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
      priority_queue<int, vector<int>, greater<int> > pq;
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
  vector<int> test = {3, 2, 1, 5, 6, 4};
  Solution S;
  int res = S.findKthLargest(test,2);
  return 0;
}
