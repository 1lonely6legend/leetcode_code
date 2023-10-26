//
// Created by ogier on 2023/10/26.
//

//和904对比看，这种滑动窗口并且要考虑元素个数的可以使用哈希表计数，只考虑和的就不用了

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
	unordered_map <char, int> ori, cnt;

	bool check() {
		for (const auto &p: ori) {
			if (cnt[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string minWindow(string s, string t) {
		for (const auto &c: t) {
			++ori[c];
		}

		int l = 0, r = -1;
		int len = INT_MAX, ansL = -1, ansR = -1;

		while (r < int(s.size())) {
			if (ori.find(s[++r]) != ori.end()) {
				++cnt[s[r]];
			}
			while (check() && l <= r) {
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}
				if (ori.find(s[l]) != ori.end()) {
					--cnt[s[l]];
				}
				++l;
			}
		}

		return ansL == -1 ? string() : s.substr(ansL, len);
	}
};

int main() {
	string a = "ADOBECODEBANC";
	string b = "ABC";
	Solution S;
	string s = S.minWindow(a, b);
	return 0;
}

/*
class Solution {
 public:
	string minWindow(string s, string t) {

		//建立一个哈希表，存放t中的元素,方便检索s中的元素是否在t中
		unordered_set<char> table;
		for (auto c : t) {
			table.emplace(c);
		}

//		//建立第二个哈希表，存放窗口中字符的数量，方便窗口左端大小调整
//		unordered_map<char, int> windows;
		//建立第三个哈希表，存放窗口中在t中的字符的数量，方便窗口左端大小调整
		unordered_map<char, int> count;

		//建立一个数组，存放s中的元素，方便下标计算
		vector<char> temp;
		for (auto c : s) {
			temp.push_back(c);
		}

		int left = 0;
		int right = 0;
		int res = INT_MAX;
		int size = table.size();//确定t中的字符数量

		for (; right < temp.size(); ++right) {
			if (table.find(temp[right]) != table.end()) {
				//当前元素是t中的元素时
				++count[temp[right]];
			}

			if (count.size() == size)
				res = min(res, right - left + 1);
			///////////////////////////////
			//关键是判断什么时候可以去缩小窗口的大小，
			//也就是窗口中所有t的字符都存在就可以缩，直到缺少
			///////////////////////////////
			while (check(count)||table.find(temp[left]) == table.end()) {
				//当窗口中的是t的字符的数量
				if (table.find(temp[left]) != table.end()) {
					auto it = count.find(temp[left]);
					--it->second;
					if (it->second == 0) {
						count.erase(it);
					}
				}
				++left;
			}
		}
		return res == INT_MAX ? "" : s.substr(left, right);
	}


 private:
	bool check(unordered_map<char, int> count) {
		if (count.size() < 3) return false;
		for (auto it : count) {
			if (it.second > 1)
				return true;
		}
		return false;
	}
};
*/
