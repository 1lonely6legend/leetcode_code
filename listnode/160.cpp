//
// Created by ogier on 2022/10/28.
//
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *p1 = headA, *p2 = headB;//初始化指针
  while(p1!=NULL){//整体遍历第一个链表一遍
    while(p2!=NULL){//在对应的每个第一个的节点，将第二个链表遍历，看是否有对的上的
      if(p1 == p2)    return p1;//如果对的上，说明这就是答案
      else p2 = p2->next;//对不上就往后走
    }
    //如果第二链表走完一遍了就把p1指针后移，p2指针归零
    p1 = p1->next;
    p2 = headB;
  }
  //都走完了还是没找到，那就是没有相交
  return NULL;
}