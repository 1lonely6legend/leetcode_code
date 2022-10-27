//
// Created by ogier on 2022/10/26.
//pass

///////////////////////
//虽然通过了，但时间复杂度和题目的要求差的太多了
//////////////////////
#include <vector>
#include <iostream>

using std::vector;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size(), n = nums2.size();
  double ans = 0;
  if (m == 0) {//当nums1数组为空时
    int mid = n / 2;//取中
    if (n % 2 == 0) return ans = ((double) nums2[mid] + nums2[mid - 1]) / 2;
      //此时nums2为偶数个是，取中间两个的平均数
    else return ans = nums2[mid];//如果是奇数个，直接取出mid的值
  }
  if (n == 0) {//同上，这次是判断nums2是否为空
    int mid = m / 2;
    if (m % 2 == 0) return ans = ((double) nums1[mid] + nums1[mid - 1]) / 2;
    else return ans = nums1[mid];
  }
  int p1 = 0, p2 = 0, p3 = 0;
  int nums3[m + n];
  while (p3 < m + n) {
    if (p1 == m)
      nums3[p3++] = nums2[p2++];
    else if (p2 == n)
      nums3[p3++] = nums1[p1++];
    else if (nums1[p1] < nums2[p2])
      nums3[p3++] = nums1[p1++];
    else
      nums3[p3++] = nums2[p2++];
  }
  int mid = (m + n) / 2;
  if (p3 % 2 == 0)
    return ans = ((double) nums3[mid] + nums3[mid - 1]) / 2;
  else
    return ans = nums3[mid];
}
int main() {
  vector<int> nums1 = {3, 4};
  vector<int> nums2 = {3};
  double ans = findMedianSortedArrays(nums1, nums2);
  std::cout << ans;
  return 0;
}