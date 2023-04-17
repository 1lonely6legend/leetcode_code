//
// Created by ogier on 2023/4/17.
// 67. 二进制求和
#include <iostream>
#include <string>
#include <algorithm>

using std::string;

string addBinary(string a, string b) {
  string ans;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());//将字符串反转,方便对齐

  int n = std::max(a.size(), b.size()), carry = 0;
  for (size_t i = 0; i < n; ++i) {
    carry += i < a.size() ? (a.at(i) == '1') : 0;
    carry += i < b.size() ? (b.at(i) == '1') : 0;
    //这两步加下来,就是这一位的值,下面再判断是否大于2
    ans.push_back((carry % 2) ? '1' : '0');
    carry /= 2;
  }

  if (carry) {//判断最后是否需要增加一位
    ans.push_back('1');
  }
  reverse(ans.begin(), ans.end());//最后再反转数组

  return ans;
}

int main() {
  string s1 = {"11"};
  string s2 = {"1"};
  std::cout << addBinary(s1, s2);
  return 0;
}
