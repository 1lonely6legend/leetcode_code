//
// Created by ogier on 2023/6/2.
// 142. 环形链表 II
#include <iostream>
#include <unordered_map>
using std::cout;
using std::unordered_map;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
  unordered_map<ListNode *, int> map;
  ListNode *dummynode = new ListNode(-1);
  dummynode->next = head;
  int index = 0;
  while (head != nullptr) {
    if (map.find(head) != map.end()) {
      //说明当前节点是之前遍历过的节点,可以直接返回结果了
      int res = map[head];
      ListNode *ans = dummynode;
      for (int i = 0; i <= res; i++) {
        ans = ans->next;
      }
      return ans;
    } else {
      //说明节点,还没有在之前便利的节点中出现过
      map[head] = index++;
    }
    head = head->next;
  }
  return nullptr;
}

int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  //head->next->next->next->next->next = new ListNode(2);
  //head->next->next->next->next->next->next = new ListNode(5);

  ListNode *ans = detectCycle(head);
  return 0;
}