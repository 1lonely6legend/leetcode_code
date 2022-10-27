//
// Created by ogier on 2022/10/27.
//
//
// Created by ogier on 2022/10/27.
//
#include <iostream>
using namespace std;
//Definition for singly-linked list.


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
///////////////////////////////////////////
//妈的，没写出来别人想的快慢指针，两个指针一个走两步一个走一步，早晚会相遇
//////////////////////////////////////////
bool hasCycle(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    // 快慢指针相遇，说明有环
    if (slow == fast) return true;
  }
  return false;
}

int main() {
  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(1);
  head->next->next->next = head;
  bool ans = hasCycle(head);
  cout << ans;
  return 0;
}