//
// Created by ogier on 2023/4/6.
//

#include <iostream>
#include <string>

using std::string;

int romanToInt(string s) {
  int ans = 0;
  int qianyigezhi = 2000;//设定一个大数>1000,第一次一定不会判断为特殊
  int tmp = 0;
  for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
/*    if (*iter == 'I') {
      tmp = 1;
    }
    if (*iter == 'V') {
      tmp = 5;
    }
    if (*iter == 'X') {
      tmp = 10;
    }
    if (*iter == 'L') {
      tmp = 50;
    }
    if (*iter == 'C') {
      tmp = 100;
    }
    if (*iter == 'D') {
      tmp = 500;
    }
    if (*iter == 'M') {
      tmp = 1000;
    }*/
    switch (*iter) {
      case 'I': tmp = 1; break;
      case 'V': tmp = 5; break;
      case 'X': tmp = 10; break;
      case 'L': tmp = 50; break;
      case 'C': tmp = 100; break;
      case 'D': tmp = 500; break;
      case 'M': tmp = 1000; break;
    }
    if (tmp > qianyigezhi){
      return ans - qianyigezhi*2 + romanToInt(s.substr(std::distance(s.begin(),iter)));
    }else{
      ans += tmp;
      qianyigezhi = tmp;
    }
  }
  return ans;
}

int main() {
  string s = "IV";
  int ans = romanToInt(s);
  std::cout << ans;
  return 0;
}
