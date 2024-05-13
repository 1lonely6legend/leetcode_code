//
// Created by ogier on 24-5-11.
//
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    for (int num : nums) {
      set.insert(num);
    }
    int res = 0;
    for (auto iter : set) {
      int temp_length = 0;
      if (set.find(iter - 1) == set.end()) {
        temp_length = 1;
        while (set.find(iter + 1) != set.end()) {
          temp_length++;
          iter++;
        }
        res = max(res, temp_length);
      }
    }
    return res;
  }
};

int main() {
  vector<int> test = {100, 4, 200, 1, 3, 2};
  Solution S;
  auto res = S.longestConsecutive(test);
  return 0;
}

class Solution2 {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set;
    for(const int & num : nums){
      set.insert(num);
    }
    int longestStreak = 0;
    for(const int &num : nums){
      if(!set.count(num - 1)){
        int currentNum = num;
        int currentStreak = 1;
        while(set.count(currentNum + 1)){
          currentNum += 1;
          currentStreak += 1;
        }
        longestStreak = max(longestStreak,currentStreak);
      }
    }
    return longestStreak;
  }
};
