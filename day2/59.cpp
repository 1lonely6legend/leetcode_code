//
// Created by ogier on 2023/10/26.
// 59.螺旋矩阵Ⅱ

// 类似二分法，这个也是关键要找一个循环不变量
// 没有什么算法，单纯一个模拟题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n));
		int startx = 0;
		int starty = 0;
		int loop = n / 2;
		int mid = n / 2;
		int count = 1;
		int offset = 1;
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;
			for (j = starty; j < n - offset; j++) {
				res[startx][j] = count++;
			}
			for (i = startx; i < n - offset; i++) {
				res[i][j] = count++;
			}
			for (; j > starty; j--) {
				res[i][j] = count++;
			}
			for (; i > startx; i--) {
				res[i][j] = count++;
			}
			offset++;
			startx++;
			starty++;
		}
		if (n % 2 == 1) {
			res[mid][mid] = count;
		}
		return res;
	}
};