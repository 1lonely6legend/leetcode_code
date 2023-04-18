//
// Created by ogier on 2023/4/18.
// 125. 验证回文串
// https://leetcode.cn/problems/valid-palindrome/?envType=study-plan-v2&id=top-interview-150
// 使用双指针

//有关的函数isalum() iaalpha() islower() isupper()
// tolower() toupper()


#include <iostream>
#include <string>
#include <algorithm>

using std::string;

bool isPalindrome(string s) {
  //定义前后指针
  auto iter_front = s.begin();
  auto iter_rear = s.end() - 1;
  bool ans = true;//初始化返回结果
  while (iter_front < iter_rear) {
    while (iter_front < iter_rear && !std::isalnum(*iter_front))//isalnum判断当前这个字符是不是字母或者数字,
      ++iter_front;
    while (iter_front < iter_rear && !std::isalnum(*iter_rear))
      --iter_rear;
    if (iter_front < iter_rear) {//首先要保证比较时,上文的while是因为找到字符退出,而不是找完了退出
      if (tolower(*iter_rear) != tolower(*iter_front))//判断时要保证统一大小写
        return false;//如果匹配失败直接就可以返回了
      ++iter_front;
      --iter_rear;
    }
  }
  return ans;
}

int main() {
  string s = {"race a car"};
  bool ans;
  ans = isPalindrome(s);
  std::cout << ans;
  return 0;
}

