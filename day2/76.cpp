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
	//建立两个HashMap，
	//ori用于存储目标字符串t中每个字符的出现次数
	//cnt用于存储当前窗口中是t中的字符的出现次数。
	unordered_map <char, int> ori, cnt;

	//判断当前窗口是否包含了目标字符串t的所有字符。(种类和数量都要匹配)
	bool check() {
		for (const auto &p: ori) {
			if (cnt[p.first] < p.second) {
				//如果窗口内的每个字符和它的数量，只要有一个比目标字符串中的字符少，当前窗口肯定不符合了
				return false;
			}
		}
		//符合
		return true;
	}

	string minWindow(string s, string t) {
		//遍历目标字符串t，将每个字符及其出现次数存入ori中
		for (const auto &c: t) {
			++ori[c];
		}

		int l = 0, r = -1;
		//l窗口左边界，r窗口右边界
		//ansL和ansR用于存储最小覆盖子串的起始位置和结束位置。
		int len = INT_MAX, ansL = -1, ansR = -1;

		//开始遍历
		while (r < int(s.size())) {
			//遍历原字符串s，右指针r向右移动。若r未越界且当前字符存在于ori中，则将其添加至cnt中并增加其出现次数。
			if (ori.find(s[++r]) != ori.end()) {
				//存放窗口内不同目标字符的数量
				++cnt[s[r]];
			}
			//判定这个窗口是否符合题目中的要求
			while (check() && l <= r) {
				//比较窗口大小,如果你后面符合的窗口都比我现在大，就没必要更新了，继续缩短窗口
				if (r - l + 1 < len) {
					len = r - l + 1;//更新为窗口大小
					ansL = l;//符合的左边边界下标就是窗口的左边界
				}
				//若左指针指向的字符存在于ori中，则在cnt中减少其出现次数。（因为现在要开始向后移动窗口的左边界）
				//如果是普通字符就只是简单的移动指针就叫可以了，如果是目标字符，就要减少窗口这个字符的数量
				if (ori.find(s[l]) != ori.end()) {
					--cnt[s[l]];
				}
				//窗口左边界向后移动，缩小窗口
				++l;
			}
		}
		//返回最小覆盖子串，若ansL为-1，则说明不存在，返回空串。否则，返回s中从ansL到ansR的子串
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
