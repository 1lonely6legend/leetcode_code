//
// Created by ogier on 23-11-24.
// 376.摆动序列
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
  public:
    int wiggleMaxLength(vector<int>&nums) {
      //需要记录的是相邻flag不同的情况，既然可以去掉中间的数字
      //设置flag记录每次是上升还是下降，每次比较两次是否不同
      int flag = 0; //-1 = down  1 = up
      int res = 1;
      for (int i = 1; i < nums.size(); ++i) {
        //如果有前后两个数字相同，保持flag不变
        if (nums[i] > nums[i - 1]) {
          if (flag <= 0)
            res++;
          flag = 1;
        }
        else if (nums[i] < nums[i - 1]) {
          if (flag >= 0)
            res++;
          flag = -1;
        }
      }
      return res;
    }
};
int main() {
  vector<int> test = {1, 7, 4, 9, 2, 5};
  Solution S;
  auto res = S.wiggleMaxLength(test);
  return 0;
}
