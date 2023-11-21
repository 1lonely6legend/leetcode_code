//
// Created by ogier on 2023/11/20.
// 93.复原IP地址
// 感觉判断回文串，有点像，找分割点和插入点有点类似
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class SolutionGPT {
 public:
	// 主函数，用于初始化并调用递归函数
	vector<string> restoreIpAddresses(string s) {
		vector<string> res; // 用于存储所有有效的 IP 地址
		if (s.size() < 4 || s.size() > 12)return res;
		string path; // 当前构建的 IP 地址字符串
		backtracking(s, 0, 0, path, res); // 开始递归
		return res; // 返回所有有效的 IP 地址
	}
 private:
	// 递归函数，用于构建 IP 地址
	void backtracking(const string &s, int start, int dotCount, string &path, vector<string> &res) {
		if (dotCount == 4) { // 当已插入 4 个点时
			if (start == s.size()) { // 如果所有字符都已使用
				res.push_back(path.substr(0, path.size() - 1)); // 添加到结果中（去除末尾的点）
			}
			return; // 返回上一层递归
		}

		for (int i = start; i < s.size(); i++) {
			if (i - start > 2) break; // 如果数字长度超过 3 位，则终止循环
			if (i > start && s[start] == '0') break; // 如果遇到前导零，则终止循环

			string segment = s.substr(start, i - start + 1); // 截取子字符串作为 IP 地址的一部分
			int val = stoi(segment); // 将字符串转换为整数
			if (val > 255) break; // 如果整数值大于 255，则终止循环,后面的只会更大

			path += segment + '.'; // 将当前段和点添加到路径中
			backtracking(s, i + 1, dotCount + 1, path, res); // 递归调用，移动到下一个部分
			path = path.substr(0, path.size() - segment.size() - 1); // 回溯，移除刚刚添加的部分和点
		}
	}
};

int main() {
	string test = "25525511135";
	SolutionGPT S;
	auto res = S.restoreIpAddresses(test);
	return 0;
}