//
// Created by ogier on 23-4-26.
// 191. 位1的个数

#include <iostream>
#include <string>

//答案做法,时间复杂度,O(log32)
//我是真想不到https://leetcode.cn/problems/number-of-1-bits/solution/wei-1de-ge-shu-by-leetcode-solution-jnwf/
//用这个n &= n - 1,NBA
/*int hammingWeight(uint32_t n) {
  int ret = 0;
  while (n) {
    n &= n - 1;
    ret++;
  }
  return ret;
}*/

//我写的,需要遍历每一位,O(32)
int hammingWeight(uint32_t n) {
  int res = 0;
  for (int i = 0; i < 32; ++i) {
    if (n & 1)
      ++res;
    n >>= 1;
  }
  return res;
}
//区分n>>1和n>>=1

int main() {
  uint32_t n = 00000010100101000001111010011100;
  std::cout << hammingWeight(n);
  return 0;
}


