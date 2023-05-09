//
// Created by ogier on 2023/5/9.
// 380. O(1) 时间插入、删除和获取随机元素

#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

//官方答案,变长数组加上哈希表

class RandomizedSet {
 public:
  RandomizedSet() {
    //使用当前系统时间作为随机数生成器的种子,srand接受一个整数值作为种子
    //这样每次运行生成的随机数都不一样,提高随机性,会影响后续的rand()函数
    srand((unsigned)time(NULL));
  }

  bool insert(int val) {
    if (indices.count(val)) {
      //首先在哈希表中查找是否存在该元素,如果存在则返回false
      return false;
    }
    //如果不存在,则在数组最后插入该元素,并在哈希表中添加该元素的索引
    int index = nums.size();
    nums.emplace_back(val);
    indices[val] = index;
    return true;
  }

  bool remove(int val) {
    if (!indices.count(val)) {
      //首先在哈希表中查找是否存在该元素,如果不存在则返回false
      return false;
    }
    //如果查找到了,首先获取该元素的索引,然后将该元素与数组最后一个元素交换
    //感觉这个和最后一个交换很妙啊,这样就不用移动数组了
    //其实也不需要每个数的index移植和他对齐,只要能保证索引和总个数一样即可
    int index = indices[val];
    int last = nums.back();
    //交换
    nums[index] = last;
    indices[last] = index;
    //删除最后一个元素
    nums.pop_back();
    //在哈希表中删除该元素
    indices.erase(val);
    return true;
  }

  int getRandom() {
    //随机生成一个索引,然后返回该索引对应的元素
    int randomIndex = rand()%nums.size();
    return nums[randomIndex];
  }
 private:
  //私有变量有一个数组和一个哈希表
  vector<int> nums;
  unordered_map<int, int> indices;
};