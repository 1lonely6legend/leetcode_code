//
// Created by ogier on 23-11-28.
// 860.柠檬水找零
#include <vector>
using namespace std;
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
      if (bill == 5) five++;
      if (bill == 10) {
        if (five <= 0) return false;
        ten++;
        five--;
      }
      if (bill == 20) {
        if (five > 0 && ten > 0) {
          ten--;
          five--;
        } else if (five >= 3) {
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { 
  vector<int> test = {5,5,10,10,20};
  Solution S;
  auto res = S.lemonadeChange(test);
  return 0;
}