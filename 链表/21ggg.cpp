//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
      if (list1 == nullptr) {
        return list2;
      } else if (list2 == nullptr) {
        return list1;
      } else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
    }
};
class Solution2 {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
      ListNode *dummyhead = new ListNode(-1);
      ListNode *pre = dummyhead;
      while (list1 && list2) {
        if (list1->val < list2->val) {
          pre->next = list1;
          list1 = list1->next;
        } else {
          pre->next = list2;
          list2 = list2->next;
        }
        pre = pre->next;
      }
      // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
      pre->next = (list1 == nullptr) ? list2 : list1;
      return dummyhead->next;
    }
};
