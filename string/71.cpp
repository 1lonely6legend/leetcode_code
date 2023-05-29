//
// Created by ogier on 23-5-29.
// 71. 简化路径
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using std::string;
using std::stack;
using std::vector;
string simplifyPath(string path) {
  auto split = [](const string &s, char delim) -> vector<string> {
    vector<string> ans;
    string cur;
    for (char ch : s) {
      if (ch == delim) {
        ans.push_back(std::move(cur));
        cur.clear();
      } else {
        cur += ch;
      }
    }
    ans.push_back(std::move(cur));
    return ans;
  };

  vector<string> names = split(path, '/');
  vector<string> stack;
  for (string &name : names) {
    if (name == "..") {
      if (!stack.empty()) {
        stack.pop_back();
      }
    } else if (!name.empty() && name != ".") {
      stack.push_back(std::move(name));
    }
  }
  string ans;
  if (stack.empty()) {
    ans = "/";
  } else {
    for (string &name : stack) {
      ans += "/" + std::move(name);
    }
  }
  return ans;
}

int main() {
  string path = "/a/./b/../../c/";
  string res = simplifyPath(path);
  std::cout << res << std::endl;
  return 0;
}