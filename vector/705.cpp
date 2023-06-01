//
// Created by ogier on 2023/6/1.
// 705. 设计哈希集合
#include <list>
#include <vector>
using std::vector;
using std::list;
#define MAX_LEN 100000
class MyHashSet {
 private:
  vector<int> set[MAX_LEN];

  /* 返回相应的表索引 */
  int getIndex(int key) {
    return key % MAX_LEN;
  }

  /* 搜索特定存储哈希表中的值。如果值不存在，则返回-1 */
  int getPos(int key, int index) {
    for (int i = 0; i < set[index].size(); ++i) {
      if (set[index][i] == key) {
        return i;
      }
    }
    return -1;
  }
 public:
  MyHashSet() {
  }
  /* 向哈希集合中插入值key */
  void add(int key) {
    int index = getIndex(key);
    int pos = getPos(key, index);
    /* 如果不存在则添加新的数据进去 存在不做任何操作 */
    if (pos < 0) {
      set[index].push_back(key);
    }
  }
  /* 将给定值key从哈希集合中删除 */
  void remove(int key) {
    int index = getIndex(key);
    int pos = getPos(key, index);
    if (pos >= 0) {
      set[index].erase(set[index].begin() + pos);
    }
  }

  /** 返回哈希集合中是否存在这个值 key */
  bool contains(int key) {
    int index = getIndex(key);
    int pos = getPos(key, index);
    return pos >= 0;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
