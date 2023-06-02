//
// Created by ogier on 2023/6/1.
// 82. 删除排序链表中的重复元素 II

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  if (!head) {
    return head;
  }

  ListNode* dummy = new ListNode(0, head);

  ListNode* cur = dummy;
  while (cur->next && cur->next->next) {
    if (cur->next->val == cur->next->next->val) {
      int x = cur->next->val;
      while (cur->next && cur->next->val == x) {
        cur->next = cur->next->next;
      }
    }else {
      cur = cur->next;
    }
  }
  return dummy->next;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  ListNode *ans = deleteDuplicates(head);
  return 0;
}

