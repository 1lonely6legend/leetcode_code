//
// Created by ogier on 2022/10/28.
//
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA, *p2 = headB;
    while(p1!=NULL){
      while(p2!=NULL){
        if(p1 == p2)    return p1;
        if(p1 == p2->next) return p1;
        else p2 = p2->next;
      }
      p1 = p1->next;
      p2 = headB;
    }
    return NULL;
  }
};