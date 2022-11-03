//
// Created by ogier on 2022/11/2.
// 一次过,空间击败82时间击败92,好耶
#include<iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (head == nullptr || head->next == nullptr) return head;
  int num = 1;
  ListNode *p = head;
  while (p->next != nullptr) {
    num++;
    p = p->next;
  }
  p->next = head;
  p = head;
  int i = 1;
  while (i < num - (k % num)) {//关键点
    p = p->next;
    i++;
  }
  ListNode *ans = p->next;
  p->next = nullptr;//关键点
  return ans;
}

int main() {
  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  //head->next->next = new ListNode(2);
  //head->next->next->next = new ListNode(4);
  //head->next->next->next->next = new ListNode(5);
  ListNode *ans = rotateRight(head, 4);
  return 0;
}