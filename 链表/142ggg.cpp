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
    ListNode *detectCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr)
        return nullptr;
      ListNode *p1 = head, *p2 = head;
      do {
        if (p2 == nullptr || p2->next == nullptr)
          return nullptr;
        p1 = p1->next;
        p2 = p2->next->next;
      } while (p1 != p2);
      p1 = head;
      while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
      }
      return p1;
    }
};
int main() {
  ListNode *p1 = new ListNode(1);
  ListNode *p2 = new ListNode(2);
  p1->next = p2;
  p2->next = p1;
  Solution S;
  auto res = S.detectCycle(p1);
  return 0;
}
