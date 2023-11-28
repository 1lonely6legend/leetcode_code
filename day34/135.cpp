//
// Created by ogier on 23-11-27.
// 135.分发糖果
#include <vector>
#include <climits>
using namespace std;
class Solution {
 public:
  int candy(vector<int> &ratings) {
    vector<int> candyVec(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1])
        candyVec[i] = candyVec[i - 1] + 1;
    }
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
      }
    }
    int res = 0;
    for (auto num : candyVec) {
      res += num;
    }
    return res;
  }
};
int main() {
  vector<int> test = {1, 2, 2};
  Solution S;
  auto res = S.candy(test);
  return 0;
}