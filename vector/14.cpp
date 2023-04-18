//
// Created by ogier on 2023/4/17.
// 14. 最长公共前缀
//我这个算纵向查找,还有其余的方法,详见:
//https://leetcode.cn/problems/longest-common-prefix/solution/zui-chang-gong-gong-qian-zhui-by-leetcode-solution/
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

string longestCommonPrefix(vector<string>& strs) {
  //整体思路:拿出第一个字符串的第i个字符,再和后面的字符串的第i个比较
  int size = strs[0].length();//首先确定第一个长度,公共前缀的长度不可能比任何一个词大
  int ans = 0;//前几位是相同的
  bool full_cycle = true;//用来后面判断是否是把所有string都检查了一遍
  for(int i = 0;i<size;++i){//把第一个字符串的所有字符遍历一遍
    auto ptr = strs[0][i];//ptr指向当前要检查的字符
    for(auto iter = strs.begin()+1;iter<strs.end();iter++){//遍历除了第一个后面的字符串
      if( (*iter)[i] == ptr) continue;//判断这些字符串的对应位置的字符,是否和第一个的一样,是的话直接continue进行下一个循环
      full_cycle = false;//如果能走到这里,说明有的词不一样,检查到此位置,直接结束可以返回ans了
      break;//跳出for循环
    }
    if(full_cycle){//对full_cycle进行一个判断,看是不是正常跳出for循环(说明这一位字符大伙都一样)
      ++ans;
    }else{//非正常跳出对比循环
      break;//可以结束对比了
    }
  }
  return strs[0].substr(0,ans);//使用substr方法返回前面的几个字符
}

int main() {
  vector<string> strings = {"flower","flow","flight"};
  std::cout << longestCommonPrefix(strings);
  return 0;
}

