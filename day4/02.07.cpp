//
// Created by ogier on 2023/10/28.
// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
// 02.07.链表相交
#include <iostream>
#include <unordered_set>
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> set;
		ListNode *ptr1 = headA;
		while (ptr1 != nullptr) {
			set.emplace(ptr1);
			ptr1 = ptr1->next;
		}
		ListNode *ptr2 = headB;
		while (ptr2 != nullptr) {
			if (set.find(ptr2) != set.end()) {
				return ptr2;
			}
			ptr2 = ptr2->next;
		}
		return nullptr;
	}
};