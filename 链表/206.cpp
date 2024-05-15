//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <unordered_set>
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
    ListNode *reverseList(ListNode *head) {
      ListNode *cur = head, *pre = nullptr, *next = nullptr;
      while(cur!=nullptr) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      //这样最后停下时，cur == nullptr，所以最后的头结点是前一个pre
      return pre;
    }
};
