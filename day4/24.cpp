//
// Created by ogier on 2023/10/28.
// 24.两两交换链表中的节点
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
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *dummyhead = new ListNode(-1, head);
		ListNode *pre = dummyhead;
		ListNode *cur = head;
		ListNode *next = nullptr;
		//防止next访问到空，每次首先判断cur和cur->next,在移动next
		while (cur != nullptr && cur->next != nullptr) {
			//下面的情况下，cur和next一定都存在
			next = cur->next;
			cur->next = next->next;
			pre->next = next;
			next->next = cur;
			//换成下一次循环的cur和pre
			pre = cur;
			cur = cur->next;
		}
		return dummyhead->next;
	}
};
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution S;
	ListNode *res = S.swapPairs(head);
	return 0;
}