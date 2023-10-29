//
// Created by ogier on 2023/10/29.
// 138.随机链表的复制

//总体思想是制造一个map-map哈希表，第一次遍历，value新建res节点
//第二次遍历，使用key找到对应的next和random‘s key节点  ----自然可以找到深复制之后的对应的value节点

#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
 public:
	int val;
	Node *next;
	Node *random;
	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class Solution {
 public:
	Node *copyRandomList(Node *head) {
		unordered_map<Node *, Node *> map;
		Node *cur = head;
		while (cur != nullptr) {
			map[cur] = new Node(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr) {
			map[cur]->next = map[cur->next];
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}
		return map[head];
	}
};