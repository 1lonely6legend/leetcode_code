//
// Created by ogier on 2023/12/18
// 392.判断子序列
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  bool isSubsequence(string s, string t){
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    for(int i = 1; i <= s.size(); ++i){
      for(int j = 1; j <= t.length(); ++j){
        if(s[i-1] == t[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = dp[i][j-1];
      }
    }
    if(dp[s.length()][t.length()] == s.size())
      return true;
    return false;
  }
};
