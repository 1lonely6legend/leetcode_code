//
// Created by ogier on 2022/10/29.
//

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *removeElements(ListNode *head, int val) {//采用递归
  if (head == nullptr) {
    return head;
  }
  head->next = removeElements(head->next, val);
  return head->val == val ? head->next : head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(1);
  int val = 1;
  ListNode *ans = removeElements(head, 1);
  cout << ans;
  return 0;
}