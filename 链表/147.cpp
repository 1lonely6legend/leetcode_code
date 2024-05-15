//
// Created by ogier on 24-5-15.
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
    ListNode *insertionSortList(ListNode *head) {
      if(head == nullptr)  return nullptr;
      ListNode *p1 = head;
      ListNode *dummyhead = new ListNode(-1);
      ListNode *cur = dummyhead, *next = nullptr;
      while (p1) {
        cur = dummyhead;
        while (cur->next && cur->next->val < p1->val) {
          cur = cur->next;
        }
        next = cur->next;
        cur->next = new ListNode(p1->val);
        cur->next->next = next;
        p1 = p1->next;
      }
      return dummyhead->next;
    }
};

int main() {
  auto p4 = new ListNode(3);
  auto p3 = new ListNode(1, p4);
  auto p2 = new ListNode(2, p3);
  auto p1 = new ListNode(4, p2);
  Solution S;
  auto res = S.insertionSortList(p1);
  return 0;
}


class Solution2 {
  public:
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* lastSorted = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
      if (lastSorted->val <= curr->val) {
        lastSorted = lastSorted->next;
      } else {
        ListNode *prev = dummyHead;
        while (prev->next->val <= curr->val) {
          prev = prev->next;
        }
        lastSorted->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
      }
      curr = lastSorted->next;
    }
    return dummyHead->next;
  }
};