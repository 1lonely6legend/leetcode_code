#include <iostream>
#include <string>

using std::string;

int lengthOfLongestSubstring(std::string s) {
  unsigned long long size = s.length();
  if (size == 0) return 0;
  if (size == 1) return 1;
  //设置三个指针，p1指向检测窗口的左端，p3指向检测窗口的右端，p2在窗口中扫描遍历一遍，检测窗口中是否有与p3重复的元素
  unsigned long long p1 = 0, p2 = 0, p3 = 1;
  unsigned long long ans = 1;//返回无重复字串的最长值
  unsigned long long num = 1;//遍历中的计数器
  while (p3 < size) {//最外层循环，直到扫描窗口走到头
    num = 1;
    while (s[p2] != s[p3] && p2 != p3) {//窗口扫描循环，移动p2检测一遍窗口中有无p3的重复元素
      num++;
      p2++;
    }//当这个while循环退出时两种情况
    /*1.检测窗口中出现了与p3重复的元素
    2.p2与p3重合说明检测没问题*/
    ans = ans >= num ? ans : num;
    if (p2 != p3) {//如果窗口中出现重复元素，重复元素之间的距离一定小于上一次的ans，所以舍去。
      //将p1指针移到p2所指的重复元素位置的后一位处
      p2++;
      p1 = p2;
      p3 = p2+1;
    } else {
      p3++;
      p2 = p1;
    }
  }
  return ans;
}

int main() {
  string s = {"aab"};
  int ans = lengthOfLongestSubstring(s);
  std::cout<<ans;
  return 0;
}
