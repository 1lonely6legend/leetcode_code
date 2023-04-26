//
// Created by ogier on 23-4-26.
// 55. 跳跃游戏,md最后还是看别人的答案 有md
// 看清楚题里面写的是可以跳跃的最大长度,这可难太多了
// *****如果一个位置可以到达,那么这个数的左边所有数都可以到达(因为现在都是走的最大步数,中间的没有走的,少跳两步就可以了).*****
#include <iostream>
#include <vector>

using std::vector;

//可能的情况,1.最后跳出数组范围 2.最后会遇见0,卡在某一位置
//我写的垃圾,也没写出来
/*bool fun(vector<int> &nums, int i, int size) {
  while (i < size - 1) {//在没有到最后一个位置时,需要一直加
    if (nums[i] == 0) {
      i = tmp + 1;
      continue;
    }
    tmp = i;
    i += nums[i];
  }
}
bool canJump(vector<int> &nums) {
  int size = nums.size();
  if (size == 1) return true;
  if (nums[0] == 0) return false;
  int i = 0;
  int tmp = 0;
  while (i < size - 1) {//在没有到最后一个位置时,需要一直加
    if (nums[i] == 0) {
      for()
    }
    tmp = i;
    i += nums[i];
  }
  //只要最后一个数最大能跳到超出最后一个数,那可以少跳,肯定可以到最终值
  return true;
}*/

//别人的
//关键就是理解这句话,并且运用上
//如果一个位置可以到达,那么这个数的左边所有数都可以到达(因为现在都是走的最大步数,中间的没有走的,少跳两步就可以了
bool canJump(vector<int> &nums) {
  int k = 0;//记录之前的数可以跳到的最大值
  int size = nums.size();
  for (int i = 0; i < size; ++i) {//每个数都试一试
    if (i > k) return false;//如果现在都遍历到比之前能到的位置,更靠后,说明之前没有数字可以走到这,返回false
    k = std::max(k, i + nums[i]);//一直更新,可以到达的最远为之
  }
  return true;
}



int main() {
  auto nums = vector<int>({3, 2, 1, 0, 4});
  std::cout << std::uint32_t(canJump(nums));
  return 0;
}