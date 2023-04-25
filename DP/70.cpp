//
// Created by ogier on 23-4-25.
//
#include <iostream>
#include <vector>

/*int climbStairs(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  return climbStairs(n - 1) + climbStairs(n - 2);
}*/

int climbStairs(int n) {
  std::vector<int> a = {0,1,2};
  if (n == 1) return 1;
  if (n == 2) return 2;
  for (int i = 3; i <= n; ++i) {
    a.push_back(a[i - 1] + a[i - 2]);
  }
  return *(a.end()-1);
}

int main() {
  std::cout << climbStairs(31) << '\n';
  return 0;
}
