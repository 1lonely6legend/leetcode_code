//
// Created by ogier on 24-5-15.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp;
    int count = 0;
    //传入两个参数，记录当前长度以及左括号的数量
    function<void(int, int)> dfs = [&](int length, int count){
      if(length == 2 * n){//长度等于结果要求的时候放入res中
        res.emplace_back(temp);
        return;
      }
      if(count < n){//如果左括号数量不够，那么就可以继续放
        temp += '(';
        dfs(length + 1, count + 1);
        temp.pop_back();
      }
      if(length - count < count){//如果总长度减左括号数量《 左括号数量，说明还没有一一对应的右括号
        temp += ')';
        dfs(length + 1, count);
        temp.pop_back();
      }
    };
    dfs(0, 0);
    return res;
  }
};