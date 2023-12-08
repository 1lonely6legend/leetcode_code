//
// Created by ogier on 2023/12/8.
// kama52.携带研究材料
#include <vector>
#include <iostream>
using namespace std;

void FullBagDP(const int size, const int space, const vector<int> &weight, const vector<int> &value) {
  vector<int> dp(space + 1, 0);
  for (int i = 0; i < size; ++i) {
	for (int j = weight[i]; j <= space; ++j) {
	  dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
	}
  }
  cout << dp[space] << endl;
}

int main() {
  int size, space;
  cin >> size >> space;
  vector<int> weight;
  vector<int> value;
  int loop = size;
  while (loop) {
	int weight0, value0;
	cin >> weight0 >> value0;
	weight.push_back(weight0);
	value.push_back(value0);
	loop--;
  }
  FullBagDP(size, space, weight, value);
  return 0;
}