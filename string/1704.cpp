//
// Created by ogier on 2022/11/11.
//
#include <string>
#include <iostream>
using std::string;

//关键是掌握两个函数用法吧
//substr()    find_first_of

bool halvesAreAlike(string s) {
  string a = s.substr(0, s.size() / 2);//生成新的子字符串,,,起始位置,,,子字符串长度
  string b = s.substr(s.size() / 2);
  string target = {"aeiouAEIOU"};
  int numa = 0, numb = 0;
  for (int i = 0; i < a.size(); i++) {
    if (target.find(a[i]) != -1) numa++;
  }
  for (int i = 0; i < b.size(); i++) {
    if (target.find(b[i]) != -1) numb++;
  }
  if (numa == numb)
    return true;
  else
    return false;
}

int main() {
  string s = {"textbook"};
  bool ans = halvesAreAlike(s);
  /*int temp1 = s.find("xt");
  int temp2 = s.find_first_of("aeiouAEIOU");*/
  std::cout << ans;
  return 0;
}
