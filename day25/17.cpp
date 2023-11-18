//
// Created by ogier on 2023/11/18.
// 17.电话号码的字母组合
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
 public:
	void backtracing(string number, string path, vector<string> &res,
									 int startindex, unordered_map<char, vector<char>> map) {
		if (path.size() == number.length()) {
			res.push_back(path);
			return;
		}
		char digit = number[startindex];
		vector<char> letters = map.at(digit);
		for (char letter : letters) {
			path.push_back(letter);
			backtracing(number, path, res, startindex + 1, map);
			path.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0)
			return {};
		unordered_map<char, vector<char>> map = {
				{'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
				{'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
				{'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
				{'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
		};

		vector<string> res;
		string path;
		backtracing(digits, path, res, 0, map);
		return res;
	}
};

int main() {
	string test = "23";
	Solution S;
	auto res = S.letterCombinations(test);
	return 0;
}