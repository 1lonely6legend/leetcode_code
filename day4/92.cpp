//
// Created by ogier on 2023/10/29.
// 92.反转链表

//使用头插法，很有必要再看看
//https://leetcode.cn/problems/reverse-linked-list-ii/solutions/634701/fan-zhuan-lian-biao-ii-by-leetcode-solut-teyq/?envType=study-plan-v2&envId=top-interview-150
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
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		ListNode *dummyhead = new ListNode(-1, head);
		ListNode *pre = dummyhead;
		for (int i = 0; i < left - 1; ++i) {
			pre = pre->next;
		}
		ListNode *cur = pre->next;
		ListNode *next;
		//每一次都要将当前cur->next提到pre的后面，cur后移，pre永远不变
		for (int i = 0; i < right - left; ++i) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}
		return dummyhead->next;
	}
};