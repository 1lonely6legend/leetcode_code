//
// Created by ogier on 2023/5/9.
// 28. 找出字符串中第一个匹配项的下标
// 三种方法
// https://oi-wiki.org/string/match/
//【最浅显易懂的 KMP 算法讲解】https://www.bilibili.com/video/BV1AY4y157yL
//【帮你把KMP算法学个通透！（理论篇）】https://www.bilibili.com/video/BV1PD4y1o7nd
#include <iostream>
#include <vector>
using std::string;
using std::vector;

int strStr(string haystack, string needle) {
  int size1 = haystack.size();
  int size2 = needle.size();
  if (size2 == 0) return 0;
  vector<int> next(size2);
  for (int i = 1, j = 0; i < size2; ++i) {
    while (j > 0 && needle[i] != needle[j])
      j = next[j - 1];
    if (needle[i] == needle[j])
      j++;
    next[i] = j;
  }
  for (int i = 0, j = 0; i < size1; ++i) {
    while (j > 0 && haystack[i] != needle[j])
      j = next[j - 1];
    if (haystack[i] == needle[j])
      j++;
    if (j == size2)
      return i - size2 + 1;
  }
  return -1;
}

int main() {
  string s1 = {"sadbutsad"};
  string s2 = {"sad"};
  std::cout << strStr(s1, s2);
  return 0;
}