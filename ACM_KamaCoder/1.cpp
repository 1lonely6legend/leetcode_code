// https://kamacoder.com/problem.php?id=1000
// Created by ogier on 2023/10/20.
// 1.A+B问题Ⅰ

#include <iostream>

using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) cout << a + b << endl;
}

//cin的总体功能是不是从缓冲区读取数字，并剔除空格和换行符
//cin 通常会自动处理空格、制表符、换行符等空白字符，以便正确分隔和解析不同类型的数据。
//当您使用 cin 读取数字时，它会忽略之间的空白字符，并将数字识别为输入的一部分