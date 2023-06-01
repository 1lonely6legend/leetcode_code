//
// Created by ogier on 2023/6/1.
// 138. 复制带随机指针的链表

#include <unordered_map>
using std::unordered_map;
// Definition for a Node.
class Node {
 public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

//相当于创建一个hash表,把原来的每一个节点的地址,和一个新的node的地址进行对应,
//首先便利一遍,把val填进去,再根据额hash表,把next和random链接好,然后直接返回
Node* copyRandomList(Node* head) {
  unordered_map<Node*, Node*> map;
  Node* cur = head;
  while(cur != nullptr){
    map[cur] = new Node(cur -> val);
    cur = cur -> next;
  }
  cur = head;
  while(cur != nullptr){
    map[cur] -> next = map[cur -> next];
    map[cur] -> random = map[cur -> random];
    cur = cur ->next;
  }
  return map[head];
}


int main() {
  Node *head = new Node(7);
  head->next = new Node(13);
  head->next->next = new Node(11);
  head->next->next->next = new Node(10);
  head->next->next->next->next = new Node(11);

  head->random = nullptr;
  head->next->random = head;
  head->next->next->random = head->next->next->next->next;
  head->next->next->next->random = head->next->next;
  head->next->next->next->next->random = head;

  Node *ans = copyRandomList(head);
  return 0;
}