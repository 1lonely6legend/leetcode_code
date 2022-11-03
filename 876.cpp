//
// Created by ogier on 2022/11/3.
//倒是一次过,但是复杂度不太行

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//就第一遍计算多少个节点,第二步遍历一半,找到答案节点
ListNode *middleNode(ListNode *head) {
  int num = 0;
  ListNode *p = head;
  while (p != nullptr) {
    p = p->next;
    num++;
  }//计算链表中节点的个数
  num = num/2;
  for(int i = 0; i < num; i++){
    head = head->next;
  }//找到答案要求的节点
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  //head->next = new ListNode(2);
  //head->next->next = new ListNode(3);
  //head->next->next->next = new ListNode(4);
  //head->next->next->next->next = new ListNode(5);
  //head->next->next->next->next->next = new ListNode(6);
  ListNode *ans = middleNode(head);
  return 0;
}