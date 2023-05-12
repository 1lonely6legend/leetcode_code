//
// Created by ogier on 2023/5/12.
// 12. 整数转罗马数字
// 官解https://leetcode.cn/problems/integer-to-roman/solution/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/
#include <iostream>
#include <algorithm>
using std::string;

string intToRoman(int num) {
  string res;
  int tmp = num / 1000;
  num = num % 1000;
  for (int i = 0; i < tmp; ++i) {
    res += 'M';
  }//首先把千位处理好,因为n<=3999

  //分别处理百十个位
  for (int i = 100; i > 0; i /= 10) {
    //分配不同位数的1,4,5,9
    string one, four, five, nine;
    switch (i) {
      case 100:one = "C";
        four = "CD";
        five = "D";
        nine = "CM";
        break;
      case 10:one = "X";
        four = "XL";
        five = "L";
        nine = "XC";
        break;
      case 1:one = "I";
        four = "IV";
        five = "V";
        nine = "IX";
        break;
      case 0: break;
    }

    //求得相应位数与剩余的值
    int tmp = num / i;
    num = num % i;

    //判断具体是多少
    if (tmp == 9) {
      res += nine;
    } else if (tmp >= 5) {
      res += five;
      for (int j = 0; j < tmp - 5; ++j) {
        res += one;
      }
    } else if (tmp == 4) {
      res += four;
    } else {
      for (int j = 0; j < tmp; ++j) {
        res += one;
      }
    }
  }
  return res;
}

int main() {
  int num = 1994;
  std::cout << intToRoman(num);
  return 0;
}