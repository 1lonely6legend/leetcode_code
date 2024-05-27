//
// Created by ogier on 24-5-15.
//
// 1.一个双向链表，单独的头尾哨兵节点，一个hashmap，用于存储key和节点的映射
// 2.单独设计三个函数，分别是 1.头部插入节点 2.节点移动到头部 2.删除尾部节点(注意释放空间)
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
private:
  struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
  };
  int size_ = 0;
  int capacity_ = 0;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> map;

public:
  void add_head(Node *node) {
    //头部插入节点
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }
  void move_to_head(Node *node) {
    //移动节点到头部，先更改当前链表指针(将当前节点前后相连)，再插入头部
    node->prev->next = node->next;
    node->next->prev = node->prev;
    add_head(node);
  }
  void remove_tail() {
    //链接尾部节点的前后节点，删除尾部节点
    Node *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    delete tmp;
  }
  LRUCache(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    head = new Node();
    tail = new Node();
    //头和尾节点只需要将next或者prev指向头或者尾即可，只有内部才是双向链表
    head->next = tail;
    tail->prev = head;
  }
  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;//没有找到，返回-1
    } else {
      move_to_head(map[key]);//找到了，返回值，并将节点移动到头部
      return map[key]->val;
    }
  }
  void put(int key, int value) {
    if (map.find(key) != map.end()) {//如果找到了，更新值，并将节点移动到头部
      map[key]->val = value;
      move_to_head(map[key]);
    } else {
      //原本没有，需要插入
      size++;
      Node* tmp = new Node(key, value);
      add_head(tmp);
      map.emplace(key,tmp);
      if(size_ > capacity_) {
        size_--;
        map.erase(tail->prev->key);
        remove_tail();
      }
    }
  }
};
