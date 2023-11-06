//
// Created by ogier on 2023/11/6.
// 347.前k个高频元素
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
 public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> map1;
		vector<int> res;
		for (int a : nums) {
			map1[a]++;
		}
		vector<pair<int, int>> vet(map1.begin(), map1.end());
		sort(vet.begin(),
				 vet.end(),
				 [](const pair<int, int> &x, const pair<int, int> &y) -> bool { return x.second > y.second; });
		for (int i = 0; i < k; ++i) {
			res.push_back(vet[i].first);
		}
		return res;
	}
};
int main() {
	vector<int> test = {4, 1, -1, 2, -1, 2, 3};
	Solution S;
	vector<int> res = S.topKFrequent(test, 2);
	return 0;
}