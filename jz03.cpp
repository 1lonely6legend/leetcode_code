//
// Created by ogier on 2022/11/23.
//

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*超出时间限制wcnm
int findRepeatNumber(vector<int> &nums) {
  vector<int> duibi = {-1};
  bool chongfu = false;
  int ans = -1;

  for (int i = 0; i < nums.size(); ++i) {
    for (int j = 0; j < duibi.size(); ++j) {
      if (nums[i] == duibi[j]) {
        chongfu = true;
        ans = nums[i];
        break;
      }
    }
    if (chongfu == true)
      break;
    else
      duibi.push_back(nums[i]);
  }
  return ans;
}
*/

//使用哈希表

int findRepeatNumber(vector<int> &nums) {
  unordered_map<int, int> map;

  for (int num : nums) {
    map[num]++;
    if (map[num] >= 2) return num;
  }
  return nums[nums.size() - 1];
}

int main() {
  vector<int> nums1 = {1, 2, 2, 3, 23, 23, 4};
/*  vector<int> nums2 = {3};*/
  double ans = findRepeatNumber(nums1);
  std::cout << ans;
  return 0;
}