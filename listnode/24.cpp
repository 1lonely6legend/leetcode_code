//
// Created by ogier on 2022/11/1.
//tmd一次过

#include<iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//感觉我这方法跟206反转链表的迭代法差不多,都是几个指针来回用,本题算是一个局部的反转列表吧(滑稽
ListNode *swapPairs(ListNode *head) {
  //首先有可能链表为空,单独判断一下,也就是一步判断的事,可忽略不计
  if(head == nullptr) return nullptr;
  //接下来要设置用到的四个指针,存贮地址,便于指指点点
  ListNode *ans = new ListNode(0,head);//首先设置一个头节点的前驱节点,便于返回答案
  //p1,p2是要反转的两个节点,这一对的前后节点设置为prev和next
  ListNode *prev = ans, *p1 = head, *p2 = head->next;
  ListNode *next;
  while (p2 != nullptr) {//当p2 不为空指针时,可以进行交换,还有一种p1p2都空 写在while里的break里了
    //下面这四步走下来,两个节点就反过来了
    next = p2->next;
    prev->next = p2;
    p2->next = p1;
    p1->next = next;
    //接下来要设置下一个循环的四个指针的地址
    prev = p1;
    p1 = next;//因为能走到这的话,p2一定不为空,所以最坏也就是p1 = next为空指针
    if(p1== nullptr) break;//判断一下如果是空指针,那就不用换了,直接润
    p2 = p1->next;//如果p1不为空,那么p2最坏也就是nullptr,交由下一个while语句来判断
  }
  return ans->next;//走完之后返回ans的下一个节点,也就是答案
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  ListNode *ans = swapPairs(head);
  return 0;
}