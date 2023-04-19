//
// Created by ogier on 2023/4/19.
// 383. 赎金信 有markdown
// 判断ransomNote可不可以由magazine中的字符构成
// magazine 中的每个字符只能在 ransomNote 中使用一次。
// https://leetcode.cn/problems/ransom-note/?envType=study-plan-v2&id=top-interview-150
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;

//更好方法见md
bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> map;//初始化哈希表
  for (auto elem : magazine) {
    map[elem]++;//为magazine建立哈希表,记录出现的字母以及所对应的次数
  }
  for (auto elem : ransomNote) {//遍历ransomnote
    --map[elem];//在magazine中对应的次数减一
    if (map[elem] < 0)//如果有被减到负数的,说明寄,不够用
      return false;
  }
  return true;
}

int main() {
  string s1 = {"aa"};
  string s2 = {"aab"};
  bool ans;
  ans = canConstruct(s1, s2);
  std::cout << ans;
  return 0;
}


