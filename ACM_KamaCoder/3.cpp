//
// Created by ogier on 2023/10/20.
//
#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == b && a == 0) {
			return 0;
		}
		cout << a + b << endl;
	}
	return 0;
}