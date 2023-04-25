#include <cmath>
#include <iostream>
// 感觉是纯数学问题,,,,
// 因为返回整数部分,返回结果是满足ans^2<=x的最大ans
// 直接看答案了,牛顿迭代法或二分查找

using std::cout;

// 二分查找
// int mySqrt(int x) {
//   int l = 0, r = x, ans = -1;
//   while (l <= r) {
//     // 取mid为l和r的中点
//     int mid = l + (r - l) / 2;
//     if ((long long)mid * mid <= x) {
//       // 当mid^2<=x时,记录mid,并且继续向右边搜索
//       ans = mid;
//       // 注意这里是mid+1,因为mid已经判断过了
//       l = mid + 1;
//     } else {
//       // 当mid^2>x时,向左边搜索
//       r = mid - 1;  // 注意这里是mid-1,因为mid已经判断过了
//     }
//   }
//   return ans;
// }

// 牛顿迭代法

int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }

  double C = x, x0 = x;
  while (true) {
    double xi = 0.5 * (x0 + C / x0);
    if (std::fabs(x0 - xi) < 1e-7) {
      break;
    }
    x0 = xi;
  }
  return int(x0);
}

int main() {
  cout << mySqrt(8) << '\n';
  return 0;
}