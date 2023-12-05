//
// Created by ogier on 2023/12/5.
// kama46.携带研究材料
// https://kamacoder.com/problempage.php?pid=1046
#include <vector>
#include <iostream>
using namespace std;

class Solution2Dimension {
 public:
  void bag(const int bag_space, const vector<int> &space, const vector<int> &value) {
	vector<vector<int>> dp(space.size(), vector<int>(bag_space + 1, 0));//声明一个二维dp数组

	for (int j = space[0]; j <= bag_space; ++j) {
	  dp[0][j] = value[0];//如果下标为0物品 比当前便利的背包容量大，就将其放入第一行，
	  //第一行的含义是，只考虑下标为0的物品，放到容量为`j`的背包里，可以做到最大价值。
	}

	//在二维0-1背包问题中，遍历顺序可以转换
	for (int i = 1; i < space.size(); ++i) {
	  for (int j = 0; j <= bag_space; ++j) {
		if (j < space[i])
		  //如果当前新考虑的物品直接大于背包的整个容量，直接不考虑添加此物品
		  // 防止在下面判断max中数组越界
		  dp[i][j] = dp[i - 1][j];
		else
		  //此时就要在不放这个物品，和放这个物品中，选一种更大的可能作为dp
		  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - space[i]] + value[i]);
	  }
	}
	cout << dp[space.size() - 1][bag_space] << endl;
  }
};

class Solution1Dimension {
 public:
  void bag(int bag_space, vector<int> &space, vector<int> &value) {
	vector<int> dp(bag_space + 1, 0);
	for (int i = 0; i < space.size(); ++i) {
	  for (int j = bag_space; j >= space[i]; --j) {
		dp[j] = max(dp[j], dp[j - space[i]] + value[i]);
	  }
	}
	cout << dp[bag_space] << endl;
  }
};

int main() {
  //读取acm格式输入
  int number, bag_spacce;
  std::cin >> number >> bag_spacce;
  vector<int> space;
  vector<int> value;

  int size = number;
  while (size--) {
	int temp;
	cin >> temp;
	space.push_back(temp);
  }

  size = number;
  while (size--) {
	int temp;
	cin >> temp;
	value.push_back(temp);
  }
  Solution1Dimension S1;
  S1.bag(bag_spacce, space, value);
  return 0;
}

