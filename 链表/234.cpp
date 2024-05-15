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
    bool isPalindrome(ListNode *head) {
      if (head == nullptr || head->next == nullptr)
        return true;
      stack<int> stk;
      ListNode *ptr = head;
      while (ptr) {
        stk.emplace(ptr->val);
        ptr = ptr->next;
      }
      while (head) {
        if (head->val != stk.top()) {
          return false;
        } else {
          head = head->next;
          stk.pop();
        }
      }
      return true;
    }
};
