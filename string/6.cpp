//
// Created by ogier on 2023/5/12.
// 6. N 字形变换
// 看答案,自己的又臭又长还不对 nmmd
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

string convert(string s, int numRows) {
  if (numRows == 1) return s;
  //存每一行的值
  vector<string> rows(numRows);
  // 行转向标志，极妙
  //相当于一个指针,指着rosw数组,然后上下滑动,将答案输进去
  int flag = 1;
  // 行下标索引,就是转成Z字形之后的第几行
  int idxRows = 0;
  for (int i = 0; i < s.size(); i++) {
    rows[idxRows].push_back(s[i]);
    // 更新行下标
    idxRows += flag;
    if (idxRows == numRows - 1 || idxRows == 0) {
      //当指针指向最后一行或者第一行时,就开始变向,之前是加一,现在减一
      // 转向，上——>下 | 下——>上
      flag = -flag;
    }
  }
  string res;
  for (auto row : rows) {
    // 拿到答案
    res += row;
  }
  return res;
}

int main() {
  string s = "PAYPALISHIRING";
  int num = 3;
  std::cout << convert(s, num);
  return 0;
}