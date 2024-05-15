//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <unordered_set>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {
  }
};
//hash
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      unordered_set<ListNode *> set;
      ListNode *ptr = headA;
      while (ptr != nullptr) {
        set.emplace(ptr);
        ptr = ptr->next;
      }
      ptr = headB;
      while (ptr != nullptr) {
        if (set.find(ptr) != set.end()) {
          return ptr;
        }
        ptr = ptr->next;
      }
      return nullptr;
    }
};
//duiqi
class Solution2 {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *p1 = headA;
      ListNode *p2 = headB;
      if (p1 == nullptr || p2 == nullptr)
        return nullptr;
      int lena = 0, lenb = 0;
      while (p1 != nullptr) {
        lena++;
        p1 = p1->next;
      }
      while (p2 != nullptr) {
        lenb++;
        p2 = p2->next;
      }
      if (lena > lenb) {
        for (int i = 0; i < lena - lenb; ++i) {
          headA = headA->next;
        }
      } else {
        for (int i = 0; i < lenb - lena; i++) {
          headB = headB->next;
        }
      }
      while (headA != nullptr) {
        if (headA == headB) {
          return headA;
        } else {
          headA = headA->next;
          headB = headB->next;
        }
      }
      return nullptr;
    }
};
