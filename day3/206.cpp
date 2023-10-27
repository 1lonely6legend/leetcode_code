//
// Created by ogier on 2023/10/27.
// 206.反转链表
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
	ListNode *reverseList(ListNode *head) {
		ListNode *cur = head;
		ListNode *pre = nullptr;
		ListNode *next = nullptr;
		while (cur) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};