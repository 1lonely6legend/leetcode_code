//
// Created by ogier on 2023/5/18.
// 49. 字母异位词分组
// 好像用哈希表比红黑树快一点
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::map;
using std::string;
using std::unordered_map;
using std::vector;

//用哈希表
vector<vector<string>> groupAnagrams(vector<string> &strs) {
  // 首先初始化要返回的数据结构
  vector<vector<string>> res;
  //定义一个哈希表,key是排序之后的字符串,value是原来的字符串
  unordered_map<string, vector<string>> Map;
  for (int i = 0; i < strs.size(); ++i) {
    string s = strs[i];
    std::sort(s.begin(), s.end());
    Map[s].push_back(strs[i]);
  }
  //然后将每一个value都放到res中
  for (auto iter = Map.begin(); iter != Map.end(); ++iter) {
    res.push_back(iter->second);
  }
  return res;
}

//用红黑树,都差不多
/*vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> res;
  map<string, vector<string>> Map;
  for (int i = 0; i < strs.size(); ++i) {
    string s = strs[i];
    std::sort(s.begin(), s.end());
    Map[s].push_back(strs[i]);
  }
  for (auto iter = Map.begin(); iter != Map.end(); ++iter) {
    res.push_back(iter->second);
  }
  return res;
}*/

int main() {
  vector<string> strs = {""};
  auto res = groupAnagrams(strs);
  return 0;
}
