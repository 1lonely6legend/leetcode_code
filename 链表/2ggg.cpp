//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      auto dummy = new ListNode(-1);
      auto cur = dummy;
      int jinwei = 0;
      while (l1 || l2 || jinwei) {
        // 有一个不是空节点，或者还有进位，就继续迭代
        jinwei += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        cur->next = new ListNode(jinwei % 10);
        cur = cur->next;
        jinwei /= 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      return dummy->next;
    }
};
