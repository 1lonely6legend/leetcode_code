//
// Created by ogier on 2024/4/7.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int guess(int num) {
  int number = 6;
  if (num == number) return 0;
  if (num > number) return -1;
  if (num < number) return 1;
};
class Solution {
 public:
  int guessNumber(int n) {
    int res = -1;
    int left = 1;
    int right = n;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int bijiao = guess(mid);
      if (bijiao == 0)
        return mid;
      if (bijiao == 1) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution S;
  auto res = S.guessNumber(10);
  return 0;
}