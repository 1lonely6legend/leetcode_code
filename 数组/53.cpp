//
// Created by ogier on 24-5-13.
//
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution_greedy {
 public:
  int maxSubArray(vector<int> &nums) {
    int res = INT_MIN;
    int count = 0;
    for (int num : nums) {
      count += num;
      if (count > res) {
        res = count;
      }
      if (count <= 0)
        count = 0;
    }
    return res;
  }
};

class Solution_dp {
 public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      if (dp[i] > res)
        res = dp[i];
    }
    return res;
  }
};

int main() {
  vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution_dp S;
  int res = S.maxSubArray(test);
  return 0;
}