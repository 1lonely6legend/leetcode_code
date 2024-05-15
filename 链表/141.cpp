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
    bool hasCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr) {
        return false;
      }
      ListNode *p1 = head, *p2 = head;
      do {
        if (p2 == nullptr || p2->next == nullptr) {
          return false;
        }
        p1 = p1->next;
        p2 = p2->next->next;
      } while (p1 != p2);
      return true;
    }
};
