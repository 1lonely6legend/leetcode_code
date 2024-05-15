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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      auto dummyhead = new ListNode(-1, head);
      auto p1 = dummyhead, p2 = dummyhead;
      while (n--) {
        p2 = p2->next;
      }
      p2 = p2->next;
      while (p2) {
        p1 = p1->next;
        p2 = p2->next;
      }
      ListNode *del = p1->next;
      p1->next = p1->next->next;
      delete del;
      return dummyhead->next;
    }
};
