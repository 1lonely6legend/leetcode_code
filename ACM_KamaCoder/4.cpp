//
// Created by ogier on 2023/10/20.
//
#include <iostream>
using namespace std;
int main() {
	int num, temp;
	while (cin >> num) {
		if (num == 0)break;
		int sum = 0;
		while (num--) {
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}
