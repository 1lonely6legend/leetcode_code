//
// Created by ogier on 2023/6/2.
// 86. 分隔链表

//Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x) {
  //这种题首先设置dummynode,方便管理head.我这个线的头
  ListNode *dummyhead1 = new ListNode(-1);
  ListNode *dummyhead2 = new ListNode(-1);
  //这个cur就是我这个线的尾
  ListNode *cur1 = dummyhead1;
  ListNode *cur2 = dummyhead2;
  //对所给的链表进行遍历,
  while (head != nullptr) {
    if (head->val < x) {
      //把比x小的数都穿起来
      cur1->next = head;
      //更新,最新的尾部
      cur1 = cur1->next;
    } else {
      //同上
      cur2->next = head;
      cur2 = cur2->next;
    };
    //处理完这个节点,看下一个
    head = head->next;
  }
  //这个一开始忘了,因为最后cur不能保证最后一个节点就是原链表的最后一个,
  //所以要把这个线,不是我串上去的那一部分去掉
  cur2->next = nullptr;
  //将比x小的和比x大的连起来
  cur1->next = dummyhead2->next;
  return dummyhead1->next;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);
  //head->next->next->next->next->next->next = new ListNode(5);

  ListNode *ans = partition(head, 3);
  return 0;
}
