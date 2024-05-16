//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string longestPalindrome(std::string s) {
    int len = s.length();
    int left = 0, right = 0, res = 0;//res记录最长回文子串的长度, left和right记录最长回文子串的起始位置和结束位置
    //声明一个二维数组dp，dp[i][j]表示s[i]到s[j]是否是回文子串
    vector<std::vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = len - 1; i >= 0; i--) {//从后往前遍历
      for (int j = i; j < len; j++) {//从i开始遍历,因为dp[i][j]依赖于dp[i+1][j-1],所以要从后往前遍历
        if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {//如果s[i]等于s[j]并且s[i+1]到s[j-1]是回文子串,那么s[i]到s[j]也是回文子串
          dp[i][j] = true;//更新dp[i][j]为true
          if (j - i > res) {//如果当前回文子串的长度大于res,则更新res,left和right
            res = j - i;
            left = i;
            right = j;
          }
        }
      }
    }
    return s.substr(left, right - left + 1);
  }
};
class Solution2 {
public:
  pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return {left + 1, right - 1};
  }

  string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto [left1, right1] = expandAroundCenter(s, i, i);
      auto [left2, right2] = expandAroundCenter(s, i, i + 1);
      if (right1 - left1 > end - start) {
        start = left1;
        end = right1;
      }
      if (right2 - left2 > end - start) {
        start = left2;
        end = right2;
      }
    }
    return s.substr(start, end - start + 1);
  }
};