//
// Created by ogier on 24-5-15.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  void backtrack(vector<string> &res, string &cur, int open, int close, int n) {
    if (cur.size() == n * 2) {
      res.push_back(cur);
      return;
    }
    if (open < n) {
      cur.push_back('(');
      backtrack(res, cur, open + 1, close, n);
      cur.pop_back();
    }
    //如果右括号的数量小于左括号的数量，那么可以添加右括号
    if (close < open) {
      cur.push_back(')');
      backtrack(res, cur, open, close + 1, n);
      cur.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string current;
    backtrack(res, current, 0, 0, n);
    return res;
  }
};