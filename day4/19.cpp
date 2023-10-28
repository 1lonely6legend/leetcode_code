//
// Created by ogier on 2023/10/28.
// 19.删除链表的倒数第n个节点

//直接使用两个指针，差距n+1，这样后面节点到nullptr，前面的自然是要删除的前一个结点

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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *dummyhead = new ListNode(-1, head);
		ListNode *pre = dummyhead;
		ListNode *rear = dummyhead;
		n += 1;
		while (n--) {
			rear = rear->next;
		}
		while (rear != nullptr) {
			pre = pre->next;
			rear = rear->next;
		}
		ListNode *temp = pre->next;
		pre->next = pre->next->next;
		delete temp;
		return dummyhead->next;
	}
};
int main() {
	ListNode *head = new ListNode(1);
	/*head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);*/
	Solution S;
	ListNode *res = S.removeNthFromEnd(head,1);
	return 0;
}