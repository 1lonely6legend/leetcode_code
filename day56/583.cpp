//
// Created by ogier on 23-12-19
//
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2){
    int size1 = word1.length();
    int size2 = word2.length();
    vector<vector<int>> dp(size1 + 1,vector<int>(size2 + 1,0));
    for(int i = 1; i <= size1; ++i){
      for(int j = 1; j <= size2; ++j){
        if(word1[i-1] == word2[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
    return size1 + size2 - dp[size1][size2] * 2;
  }
};
