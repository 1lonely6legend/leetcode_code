//
// Created by ogier on 2023/6/2.
// 146. LRU 缓存
#include <unordered_map>
#include <iostream>
using std::cout;
using std::unordered_map;

class LRUCache {
  struct ListNode {
    int val;
    int key;
    ListNode *next;
    ListNode *pre;
    ListNode(int x, int y) : val(x), key(y), next(nullptr), pre(nullptr) {}
    ListNode(int x, int y, ListNode *next, ListNode *pre) : val(x), key(y), next(next), pre(pre) {}
  };
 public:
  LRUCache(int capacity) {
    max_num = capacity;
  }

  int get(int key) {
    if (map.find(key) != map.end()) {
      //如果map中发现已经有对应的key,然后需要把这个节点放到最前面
      //将cur的前后的节点链接起来
      ListNode *cur = map[key];
      cur->next->pre = cur->pre;
      cur->pre->next = cur->next;
      //将当前节点,放到最前面的一个节点
      cur->next = dummyhead->next;
      dummyhead->next->pre = cur;
      dummyhead->next = cur;
      cur->pre = dummyhead;
      //最后返回正确的值
      return map[key]->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      //如果key对应的节点存在,则获取此节点的地址
      ListNode *cur = map[key];
      //更新value
      cur->val = value;
      //接下来,因为最新调用了这个节点,把他提到最前面,放到dummynode后面
      //将当前节点的前后两个节点联系起来
      cur->next->pre = cur->pre;
      cur->pre->next = cur->next;
      //将当前节点,放到dunmmy节点的后面一个
      cur->next = dummyhead->next;
      dummyhead->next->pre = cur;
      dummyhead->next = cur;
      cur->pre = dummyhead;
    } else {
      if (dummyhead->val != 0) {
        //首先判断是不是只有一个节点,是否构成环形,这种情况是已经构成了环形
        //只需要构建一个节点放在第一个的位置
        ListNode *cur = new ListNode(value, key);
        map[key] = cur;
        cur->next = dummyhead->next;
        dummyhead->next->pre = cur;
        dummyhead->next = cur;
        cur->pre = dummyhead;
        //然后需要检查当前节点的总个数是否超过最大容量
        //首先容量加一
        dummyhead->val++;
      } else {
        //当前这个是链表第一个节点的情况
        ListNode *cur = new ListNode(value, key);
        map[key] = cur;
        cur->pre = dummyhead;
        cur->next = dummyhead;
        dummyhead->next = cur;
        dummyhead->pre = cur;
        dummyhead->val++;
      }
      if (dummyhead->val > max_num) {
        //如果数量超过最大值,需要把环形链表中的最后一个delete
        //首先在map中删除映射
        map.erase(dummyhead->pre->key);
        dummyhead->pre = dummyhead->pre->pre;
        //释放这个节点所占用的内存
        delete dummyhead->pre->next;
        dummyhead->pre->next = dummyhead;
        //最后总的节点数减一
        dummyhead->val--;
      }
    }
  }
 private:
  ListNode *dummyhead = new ListNode(0, -1);
  unordered_map<int, ListNode *> map;
  int max_num;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache *lru_cache = new LRUCache(2);
  lru_cache->put(1, 1);
  lru_cache->put(2, 2);
  cout << lru_cache->get(1);
  lru_cache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  cout << lru_cache->get(2);    // 返回 -1 (未找到)
  lru_cache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  cout << lru_cache->get(1);    // 返回 -1 (未找到)
  cout << lru_cache->get(3);    // 返回 3
  cout << lru_cache->get(4);
  return 0;
}