//
// Created by ogier on 2022/10/27.
//

#include <iostream>
#include <string>

using std::string;

string longestPalindrome(string s) {
  int size = s.size();
  string ans;
  if (size == 1) return ans.insert(1,s[0]);
  int start = 0, length = 1;

}

int main() {
  string s = "ASDASD";
  string ans = longestPalindrome(s);
  std::cout << ans;
  return 0;
}