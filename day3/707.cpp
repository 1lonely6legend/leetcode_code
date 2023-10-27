//
// Created by ogier on 2023/10/27.
// 707.设计链表

//注意读题，判断index和size的关系，注意判断
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList {
 public:
	MyLinkedList() {
		this->size = 0;
		this->head = new ListNode(0);
	}

	int get(int index) {
		if (index < 0 || index >= size) {
			return -1;
		}
		ListNode *cur = head;
		for (int i = 0; i <= index; i++) {
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		addAtIndex(0, val);
	}

	void addAtTail(int val) {
		addAtIndex(size, val);
	}

	void addAtIndex(int index, int val) {
		if (index > size) {
			return;
		}
		size++;
		ListNode *pred = head;
		for (int i = 0; i < index; i++) {
			pred = pred->next;
		}
		ListNode *toAdd = new ListNode(val);
		toAdd->next = pred->next;
		pred->next = toAdd;
	}

	void deleteAtIndex(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		size--;
		ListNode *pred = head;
		for (int i = 0; i < index; i++) {
			pred = pred->next;
		}
		ListNode *p = pred->next;
		pred->next = pred->next->next;
		delete p;
	}
 private:
	int size;
	ListNode *head;
};