//
// Created by ogier on 2022/10/27.
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
/*

ListNode *deleteDuplicates(ListNode *head) {
  ListNode *p1 = head, *p2 = head;//定两个指针一个是要判断是否重复，第二个是不断遍历
  //p2始终要指向的是p2后面的那个数
  while (p1 != nullptr) {//一直循环直到p1指向空指针，说明所有元素都被检查了一遍
    if((p2 = p2->next)== nullptr) return head;//首先将p2向后移动，并判断是否为空，如果空了也说明遍历完了
    //相当于p1->next == nullptr此时虽然p1不是空指针，但也不需要向后移动了
    if (p2->val == p1->val) p1->next = p2->next;//如果p2等于p1，那么就将p1指针指向后面的第二个数
    else p1 = p2;//p1向后移动
  }
  return head;
}
*/


//////////////////
//上文感觉p2直接可以换成p1->next，压根不用p2
/////////////////
ListNode *deleteDuplicates(ListNode *head) {
  ListNode *p1 = head;//定两个指针一个是要判断是否重复，第二个是不断遍历
  //p2始终要指向的是p2后面的那个数
  while (p1 != nullptr) {//一直循环直到p1指向空指针，说明所有元素都被检查了一遍
    if(p1->next == nullptr) return head;//首先将p2向后移动，并判断是否为空，如果空了也说明遍历完了
    //相当于p1->next == nullptr此时虽然p1不是空指针，但也不需要向后移动了
    if (p1->next->val == p1->val) p1->next = p1->next->next;//如果p2等于p1，那么就将p1指针指向后面的第二个数
    else p1 = p1->next;//p1向后移动
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(1);
  ListNode *ans = deleteDuplicates(head);
  cout << ans;
  return 0;
}