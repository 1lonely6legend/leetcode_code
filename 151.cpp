//
// Created by ogier on 2024/4/6.
//
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
 public:
  string reverseWords(string s) {
    s += " ";
    int size = s.size();
    int i = 0;
    for (int j = 0; j < size; ++j) {
      if (s[j] != ' ') {
        int idx = i;
        while (j < size && s[j] != ' ')
          s[i++] = s[j++];
        reverse(s.begin() + idx, s.begin() + i);
        s[i++] = ' ';
      }
    }
    s.resize(i - 1);
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() {
  string s = "  hello world  ";
  Solution S;
  auto res = S.reverseWords(s);
  return 0;
}