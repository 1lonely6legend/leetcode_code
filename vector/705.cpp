//
// Created by ogier on 23-6-5.
// 705. 设计哈希集合
#include <vector>
using std::vector;
class MyHashSet {
 public:
  MyHashSet() {
    group.resize(1000001);
  }

  void add(int key) {
    group[key] = 1;
  }

  void remove(int key) {
    group[key] = 0;
  }

  bool contains(int key) {
    if (group[key]) return true;
    return false;
  }
 private:
  vector<int> group;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */