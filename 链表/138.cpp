//
// Created by ogier on 24-5-14.
//
#include <vector>
#include <unordered_map>
#include <stack>
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
      auto ptr = head;
      unordered_map<Node *, Node *> map;
      while (ptr) {
        map[ptr] = new Node(ptr->val);
        ptr = ptr->next;
      }
      ptr = head;
      while (ptr) {
        map[ptr]->next = map[ptr->next];
        map[ptr]->random = map[ptr->random];
        ptr = ptr->next;
      }
      return map[head];
    }
};
