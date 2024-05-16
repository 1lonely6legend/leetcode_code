//
// Created by ogier on 24-5-16.
//
#include <climits>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    // 定义 dp 数组，初始值为 false，dp[i] 表示前 i 个字符是否可以被拆分成字典中的单词
    vector<bool> dp(s.size() + 1, false);

    // 初始化 dp 数组，检查字典中的单词是否可以匹配字符串 s 的前缀
    for (auto word : wordDict) {
      if (s.substr(0, word.size()) == word) {
        dp[word.size()] = true;
      }
    }

    // 遍历字符串 s 的每个位置 i
    for (int i = 1; i <= s.size(); ++i) {
      // 遍历字典中的每个单词
      for (auto word : wordDict) {
        int j = word.size();// 获取单词的长度
        // 检查字符串 s 的第 i - j 到 i 个字符是否等于当前单词,并且前 i - j 个字符可以被拆分成字典中的单词
        if (i - j >= 0 && dp[i - j] && s.substr(i - j, j) == word) {
          dp[i] = true;// 如果匹配，则更新 dp[i] 为 true
        }
      }
    }

    // 返回 dp[s.size()]，表示整个字符串 s 是否可以被拆分成字典中的单词
    return dp[s.size()];
  }
};
class Solution2 {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {   // 遍历背包
      for (int j = 0; j < i; j++) {       // 遍历物品
        string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
        if (wordSet.find(word) != wordSet.end() && dp[j]) {
          dp[i] = true;
        }
      }
    }
    return dp[s.size()];
  }
};