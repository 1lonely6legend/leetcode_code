//
// Created by ogier on 23-4-26.
// 190. 颠倒二进制位
#include <iostream>

uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i = 0; i < 32; ++i) {
    //将n做右移操作32次，每次将res左移一位，然后将n的最后一位加到res上
    //N&1,因为1只有最后一位是1，其余位都是0，所以n&1只能取到n的最后一位
    //然后再和res<<1,res<<相当于把最左边一位置为0,作或运算，这样就把n的最后一位加到了res上
    res = (res << 1) | (n & 1);
    n >>= 1;
  }
  return res;
}

int main() {
  uint32_t n = 00000010100101000001111010011100;
  std::cout << reverseBits(n);
  return 0;
}

