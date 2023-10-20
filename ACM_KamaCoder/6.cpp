//
// Created by ogier on 2023/10/20.
//
#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	while (cin >> n) {
		while (n--) {
			cin >> a;
			int sum = 0;
			while (a--) {
				cin >> b;
				sum += b;
			}
			cout << sum << endl;
			if (n != 0) cout << endl;
		}
	}
	return 0;
}
