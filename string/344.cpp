//
// Created by ogier on 2023/6/1.
// 344. 反转字符串
#include <vector>
using std::vector;
void reverseString(vector<char> &s) {
  auto iter1 = s.begin();
  auto iter2 = s.end() - 1;
  char temp;
  while (iter1 < iter2) {
    temp = *iter1;
    *iter1 = *iter2;
    *iter2 = temp;
    iter1++;
    iter2--;
  }
}
int main() {
  vector<char> s = {'h'};
  reverseString(s);
  return 0;
}