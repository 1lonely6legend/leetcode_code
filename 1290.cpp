//
// Created by ogier on 2022/11/21.
//
#include <queue>
using std::queue;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(struct ListNode* head){
  int result = 0;
  while(head){
    result <<= 1;//位运算更快
    result |= head->val;
    head = head->next;
  }

  return result;
}

int getDecimalValue(ListNode *head) {
  unsigned int ans = 0;
  while (head) {
    ans = ans * 2 + head->val;
    head = head->next;
  }
  return ans;
}

int getDecimalValue(ListNode *head) {
  ListNode *cur = head;
  int ans = 0;
  while (cur != nullptr) {
    ans = ans * 2 + cur->val;
    cur = cur->next;
  }
  return ans;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(0);
  head->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next = new ListNode(1);
  int ans = getDecimalValue(head);
  return 0;
}