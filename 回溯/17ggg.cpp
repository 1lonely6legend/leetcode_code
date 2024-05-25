//
// Created by ogier on 24-5-15.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if(digits.size() == 0) {
      return {};
    }
    string map[10] = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz",
    };
    vector<string> res;
    string path;
    function<void(int)> dfs = [&](int start) {
      if(path.size() == digits.size()) {
        res.emplace_back(path);
        return;
      }
      string temp = map[digits[start] - '0'];
      for(int i = 0; i < temp.size(); ++i) {
        path += temp[i];
        dfs(start + 1);
        path.pop_back();
      }
    };
    dfs(0);
    return res;
  }
};
