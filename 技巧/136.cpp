//
// Created by ogier on 24-5-11.
//
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    //利用异或的性质，两个相同的数异或为0，0和任何数异或为任何数
    //本题中只有一个数出现一次，其他数都出现两次，所以只需要将所有数异或一遍即可
    int res = 0;
    for (auto &x : nums) {
      res ^= x;
    }
    return res;
  }
};
