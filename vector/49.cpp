//
// Created by ogier on 2023/5/18.
// 49. 字母异位词分组
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::array;
using std::string;
using std::unordered_map;
using std::vector;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
    /*
              * accumulate()中的第四个参数项要传入一个二元操作(BinaryOperation)规则，告诉它如何将当前元素与累积量做操作
              * 它隐式地调用(size_t)acc和(int)num这两个量，默认情况下做简单的相加运算。
     */
    return accumulate(arr.begin(), arr.end(), (size_t)0, [&](size_t acc, int num) {
      return (acc << 1) ^ fn(num); // hash运算结果移位相加
    });
  };
  /*
          * 由于key的类型是array<int, 26>，属于用户自定义的一个数据类型，编译器无法针对用户自定义的数据类型做两个元素是否相等的判断
          * 所以，要告诉unordered_map你是如何确定key与key之间是否冲突(或者是否相等)的。
          * 正因如此，unordered_map的API中的第三个参数项就会让用户传入一个运算规则的函数的类型
          * 而前面写的arrayHash这个类(class)实际上是一个lambda expression(你也可以把它看作是一个仿函数(functor)的类)
          * 要获取一个显式的类的类型是容易的，但这里是隐式的，就要借助于decltype获得arrayHash的type了
          * (补充一点，lambda表达式很多都是通过decltype()的技巧获取其类型的，这也是C++11的重大进步之一)
   */
  unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
  for (string& str : strs) {
    array<int, 26> counts{};
    int length = (int)str.length();
    for (int i = 0; i < length; ++i) counts[(size_t)str[i] - 'a'] ++;
    /*
              * mp[counts]过程就会调用arrayHash计算counts的hash值
              * 在哈希表中寻找对应哈希值的篮子(busket)，并将该counts对应的str挂在对应篮子的链表尾部
              * (对于不存在的哈希值，对应的篮子是一个空链表，将str挂篮子的链表尾部这一操作仍然不变，
              * 如此一来就统一了emplace_back()的操作：只负责在篮子的链表的尾部添加string)
     */
    mp[counts].emplace_back(str);
  }
  vector<vector<string>> ans;
  for (auto it = mp.begin(); it != mp.end(); ++it) ans.emplace_back(it->second);
  return ans;
}

int main() { return 0; }
