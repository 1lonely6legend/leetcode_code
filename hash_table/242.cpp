//
// Created by ogier on 2023/4/19.
// 242. 有效的字母异位词
// https://leetcode.cn/problems/valid-anagram/solution/you-xiao-de-zi-mu-yi-wei-ci-by-leetcode-solution/
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::string;

bool isAnagram(string s, string t) {
  if(s.size()!=t.size())  return false;//注意看条件,本题没说一定等长
  int map[26] = {0};
  for (auto c : s) {
    ++map[c - 'a'];
  }//记录下s中26个字母出现的次数
  for (auto c : t) {//遍历t,并把对应出现次数减一
    --map[c - 'a'];
    if(map[c-'a']<0)
      return false;
  }
  return true;
}

int main() {
  string s1 = {"abba"};
  string s2 = {"babaa"};
  bool ans;
  ans = isAnagram(s1, s2);
  std::cout << ans;
  return 0;
}

