//
// Created by ogier on 23-4-6.
//
#include <iostream>
#include <string>

using std::string;

string baseNeg2(int n) {
  string ans;
  if (n == 0) return std::to_string(0);
  while (n) {
    if (n % -2 == -1) {
      ans.insert(0, std::to_string(1));
      n = n / -2 + 1;
    } else {
      ans.insert(0, std::to_string(n % -2));
      n = n / -2;
    }
  }
  return ans;
}

int main() {
  int a = 4;
  std::cout << baseNeg2(a);
  return 0;
}
