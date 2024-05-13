//
// Created by ogier on 24-5-13.
//
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//用滑动窗口，类似于438题的思路，但是这里需要记录最小子串的起始位置和长度
class Solution {
public:
  string minWindow(string s, string t) {
    //记录最终返回子串的起始位置和长度
    int len = INT32_MAX;
    int start;
    //声明两个hash表,1.创建要配对的字符串的查找表 2.创建当前滑动窗口内容的hash表(只考虑在t中的字符)
    unordered_map<char, int> need, window;
    //初始化查找表
    for (char c : t) need[c]++;
    //初始化滑动窗口的左右位置
    int left = 0, right = 0;
    //记录滑动窗口范围内,与待匹配子串中字符数量一致的字符个数
    int valid = 0;
    //移动窗口右边界
    while (right < s.size()) {
      char c = s[right];
      ++right;
      //判断当前字符是否是匹配的字符
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c])
          //如果数量一致,更新匹配完毕的字符
            valid++;
      }
      while (valid == need.size()) {
        //如果上面右边界,移动至一位置,可以满足已包含所有的字符,则考虑移动左指针
        if (right - left < len) {
          //在此更新最小子串长度
          start = left;
          len = right - left;
        }
        //记录要被左指针移除窗口的字符d
        char d = s[left];
        ++left;
        if (need.count(d)) {
          //如果在t中,则更新windows表
          if (window[d] == need[d])
            valid--;
          window[d]--;
        }
      }
    }
    //判断是否找到子串
    return len == INT32_MAX ? "" : s.substr(start, len);
  }
};