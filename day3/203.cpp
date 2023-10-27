//
// Created by ogier on 2023/10/27.
// 203.移除链表元素

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
	ListNode *removeElements(ListNode *head, int val) {
		ListNode *ahead = new ListNode(-1, head);
		ListNode *pl = ahead;
		ListNode *pr = head;
		while (pr != nullptr) {
			if (pr->val == val) {
				pl->next = pr->next;
				delete pr;
				pr = pl->next;
			} else {
				pr = pr->next;
				pl = pl->next;
			}
		}
		return ahead->next;
	}
};