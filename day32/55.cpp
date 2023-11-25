//
// Created by ogier on 23-11-25.
// 55.跳跃游戏
// 每一步都跳最大长度，如果最后下标越界了，代表可以到最后的位置
#include <vector>
using namespace std;
class Solution {
 public:
  bool canJump(vector<int> &nums) {
    int maxreach = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > maxreach) return false;
      maxreach = max(maxreach, i + nums[i]);
      if (maxreach >= nums.size() - 1)return true;
    }
    return false;
  }
};

int main() {
  vector<int> test = {0};
  Solution S;
  auto res = S.canJump(test);
  return 0;
}