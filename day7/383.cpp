//
// Created by ogier on 2023/10/31.
// 383.赎金信
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
 public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> map;
		for (char c : magazine) {
			map[c]++;
		}
		for (char c : ransomNote) {
			map[c]--;
			if (map[c] < 0)
				return false;
		}
		return true;
	}
};