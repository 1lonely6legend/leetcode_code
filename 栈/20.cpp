//
// Created by ogier on 24-5-13.
//
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
      int n = s.size();
      if (n % 2 == 1) {
        return false;
      }
      unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
      };
      stack<char> stk;
      for (char c : s) {
        if (map.find(c) != map.end()) {
          if (stk.empty() || stk.top() != map[c]) {
            return false;
          }
          stk.pop();
        } else {
          stk.emplace(c);
        }
      }
      return stk.empty();
    }
};
int main() {
  string s = "()";
  Solution S;
  bool res = S.isValid(s);
  return 0;
}
