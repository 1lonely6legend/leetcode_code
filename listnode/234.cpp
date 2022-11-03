//
// Created by ogier on 2022/10/31.
//

#include<iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {//直接记录当前节点的前后三个节点的位置，一次遍历直接送走
  ListNode *curr = head;//从头节点开始遍历
  ListNode *prev = nullptr,//第一个节点，反转之后是最后一个，所以定义前一个节点是空节点
  *next = nullptr;//初始化下一个节点
  while (curr) {//当当前节点不为空时就一直把指针向前指
    next = curr->next;//首先记录下下一个节点的地址
    curr->next = prev;//将当前节点的指向从后一个指向前一个节点*******最关键的操作
    //接下来是把三个前中后三个地址往后移
    prev = curr;//将前驱节点定义为当前地址
    curr = next;//将下一个地址定位当前节点
  }
  return prev;//当curr为空节点时，prev前驱节点就是最后一个有效的节点，直接返回
}

bool isPalindrome(ListNode *head) {
    ListNode *copy = new ListNode();
    ListNode *p1 = head, *p2 = copy;
    while (p1 != nullptr) {
      p2->next = new ListNode(p1->val);
      p2 = p2->next;
      p1 = p1->next;
    }
    ListNode *reverse = reverseList(copy->next);
    p1 = reverse;
    while (p1 != nullptr) {
      if (p1->val != head->val) return false;
      p1 = p1->next;
      head = head->next;
    }
    return true;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);
  //head->next->next->next = head;
  int a = isPalindrome(head);
  std::cout << a;
  return 0;
}