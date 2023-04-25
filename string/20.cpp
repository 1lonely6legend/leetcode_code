//
// Created by ogier on 2023/4/22.
// 20. 有效的括号
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using std::string;
using std::stack;
using std::cout;
using std::unordered_map;

/*//我写的真烂
//T:26,S:21
bool isValid(string s) {
  stack<char> a;
  //
  //注意只能{}才可以对上,}{不行
  //感觉其实没必要用hash表
  unordered_map<char,char> pairs ={
      {'(',')'},{'{','}'},{'[',']'}
  };
  for (auto c : s){
    if(pairs.count(c)||a.empty()){
      //pairs.count(c)判断是否是左括号,map中只存了左括号
      //如果是左边括号或者stack空的时候直接压入
      a.push(c);
      continue ;
    }
    if(pairs[a.top()] == c){
      //如果现在进来的是右括号,判断栈顶的的是否是对应的右括号
      a.pop();
    }else{
      a.push(c);
    }
  }
  return a.empty();
}*/

//别人的栈
bool isValid(string s) {
  stack<char> st;
  if(s.size() % 2 != 0)//如果长度为奇数，则一定匹配不上，返回false
    return false;

  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{')//如果是前置括号，则压入栈
    {
      st.push(s[i]);
    }
    else//到这说明此时是后置括号
    {
      if(st.empty())//如果此时栈为空，则没有可以与之匹配的，返回false
        return false;
      //如果匹配上了，则将当前栈顶元素删除，继续想字符串后进行查找匹配
      if(s[i] == ')' && st.top() == '(' ||
          s[i] == ']' && st.top() == '[' ||
          s[i] == '}' &&  st.top() == '{')
      {
        st.pop();
      }
      else//如果以上情况都不是，说明当前没有匹配上，返回false，例如( '[' 和 ‘}’ )
        return false;
    }
  }
  return st.empty();
}


int main(){
  string s = {"(){}{}"};
  bool ans = isValid(s);
  cout<<std::int32_t (ans);
  return 0;
}
