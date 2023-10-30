//
// Created by ogier on 2023/10/29.
// 242.有效的字母异位词

//对于这种元素确定是26个字母的，可以直接使用数组模拟哈希表，这样更好
// int record[26] = {0};
// record[s[i] - 'a']++;



#include <string>
#include <unordered_map>
using namespace std;
class Solution {
 public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> map;
		for (auto c : s)
			map[c]++;
		for (auto c : t) {
			map[c]--;
		}
		for(auto element:map){
			if(element.second != 0)
				return false;
		}
		return true;
	}
};