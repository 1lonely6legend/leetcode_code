//
// Created by ogier on 24-4-19.
// 69. x的平方根
#include <bits/stdc++.h>
using namespace std;
class SolutionErfen {
 public:
  int mySqrt(int x) {
    int l = 0;
    int r = x;
    int res = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if ((long long) mid * mid <= x) {
        res = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return res;
  }
};
class SolutionNewton {
 public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 - xi) < 1e-7) {
        break;
      }
      x0 = xi;
    }
    return x0;
  }
};