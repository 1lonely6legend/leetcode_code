//
// Created by ogier on 2022/11/8.
//

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int countConsistentStrings(string allowed, vector<string> &words) {
  int ans = 0, status;//ans是要返回的答案，status是一个状态量，当找不到对应的值时，置为0
  for (int i = 0; i < words.size(); ++i) {
    status = 1;//每次循环开始时将状态位重置
    for (int j = 0; j < words[i].size(); ++j) {
      //使用string中的find函数，返回该值的数组下标，找不到时返回-1
      if (allowed.find(words[i][j]) == -1) {//我看stl中写的nops，网上说实际上找不到返回的是-1
        status = 0;
        break;//当找不到这个值时直接就可以退出循环了
      }
    }
    if (status == 1) ans++;//当状态为1，说明该words值都存在于allowed中，所以计数器加一
  }
  return ans;
}

int main() {
  string allowed = {"ab"};
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
  int ans = countConsistentStrings(allowed, words);
  std::cout << ans;
  return 0;
}
