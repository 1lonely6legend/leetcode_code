//
// Created by ogier on 2023/10/26.
// 59.螺旋矩阵Ⅱ

// 类似二分法，这个也是关键要找一个循环不变量
// 没有什么算法，单纯一个模拟题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//这种方法好写，但是要明白每一个的意思，udrl，大于小于号，一个都不能写错
class Solution {
 public:
	vector<vector<int>> generateMatrix(int n) {
		int count = 1;
		int u = 0, l = 0, d = n - 1, r = n - 1;
		vector<vector<int>> res(n, vector<int>(n));
		while (true) {

			for (int i = l; i <= r; ++i) {
				res[u][i] = count++;
			}
			if (++u > d) break;

			for (int i = u; i <= d; ++i) {
				res[i][r] = count++;
			}
			if (--r < l) break;

			for (int i = r; i >= l; i--) {
				res[d][i] = count++;
			}
			if (--d < u) break;

			for (int i = d; i >= u; i--) {
				res[i][l] = count++;
			}
			if (++l > r) break;

		}
		return res;
	}
};

int main() {
	Solution S;
	auto res = S.generateMatrix(3);
	return 0;
}