//
// Created by ogier on 2023/11/19.
// 131.分割回文串
#include<vector>
#include<string>
using namespace std;

class Solution {
 public:
	bool check(const string &s, int start, int end) {
		for (int i = start, j =end; i < j; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	void backtracking(const string &s,
										int startindex,
										vector<string> &part,
										vector<vector<string>> &res) {
		if (startindex >= s.size()) {
			res.push_back(part);
			return;
		}
		for (int i = startindex; i < s.size(); ++i) {
			if (check(s, startindex, i)) {
				part.push_back(s.substr(startindex, i - startindex + 1));
			} else {
				continue;
			}
			backtracking(s, i + 1, part, res);
			part.pop_back();
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> part;
		backtracking(s, 0, part, res);
		return res;
	}
};