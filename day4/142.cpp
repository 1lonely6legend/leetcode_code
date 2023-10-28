//
// Created by ogier on 2023/10/28.
// 142.环形链表
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
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode *> set;
		ListNode *ptr = head;
		while (ptr != nullptr) {
			if (set.find(ptr) != set.end()) {
				return ptr;
			}
			set.emplace(ptr);
			ptr = ptr->next;
		}
		return nullptr;
	}
};