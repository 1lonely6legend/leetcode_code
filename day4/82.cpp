//
// Created by ogier on 2023/10/29.
// 82.删除排序链表中的重复元素

//注意读题，如果一个数字重复了，那么所有的都要删除，不是剩一个

#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
 public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)
			return head;
		ListNode *dummyhead = new ListNode(-200, head);
		ListNode *cur = dummyhead;
		while (cur->next->next != nullptr) {
			if (cur->next->val == cur->next->next->val) {
				int temp = cur->next->val;
				while (cur->next != nullptr && cur->next->val == temp) {
					ListNode *tmp = cur->next;
					cur->next = cur->next->next;
					delete tmp;
				}
				if (cur->next == nullptr) break;
			}else{
				cur = cur->next;
			}
		}
		return dummyhead->next;
	}
};
