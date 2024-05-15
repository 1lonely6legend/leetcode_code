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
    ListNode *swapPairs(ListNode *head) {
      ListNode *dummyhead = new ListNode(-1, head);
      ListNode *pre = dummyhead, *cur = head, *next = nullptr;
      while (cur && cur->next) {
        //防止next访问到空，每次首先判断cur和cur->next,在移动next,同样，这样最后剩一个无法交换，也不会处理了
        //下面的情况下，cur和next一定都存在
        next = cur->next;
        cur->next = next->next;
        next->next = cur;
        pre->next = next;
        //换成下一次循环的cur和pre
        pre = cur;
        cur = cur->next;
      }
      return dummyhead->next;
    }
};
