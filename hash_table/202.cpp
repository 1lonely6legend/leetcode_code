//
// Created by ogier on 23-4-20.
// 202. 快乐数
// https://leetcode.cn/problems/happy-number/solution/kuai-le-shu-by-leetcode-solution/
// 不会
//
#include <iostream>
#include <unordered_set>

using std::unordered_set;

//更快的快慢指针方法见md

int getsum(int n) {
  int ans = 0;//定义在函数中变量,属于动态存储值,操作系统不会帮你设置默认值
  while (n > 0) {
    ans += (n % 10) * (n % 10);
    n /= 10;
  }
  return ans;
}

bool isHappy(int n) {
  unordered_set<int> set;//初始化只有健的hashmap
  int tmp;//定义一个量,存储当前n的各位平方和
  while (true) {
    tmp = getsum(n);
    n = tmp;
    if (tmp == 1) return true;//如果是1,直接正确
    if (set.find(tmp) != set.end()) {//如果找到了值,并且不是1,进入循环,不快乐
      return false;
    } else {//没有见过的值就加入循环
      set.insert(tmp);
    }
  }
}

int main() {
  int n = 19;
  std::cout << std::int16_t(isHappy(n));
/*  std::cout << getsum(n);*/
  return 0;
}

