//
// Created by ogier on 2023/11/1.
// LCR182.动态口令
#include <string>
using namespace std;
class Solution {
 public:
	string dynamicPassword(string password, int target) {
		for (int i = 0; i < target; ++i) {
			password.push_back(password[i]);
		}
		password.erase(password.begin(), password.begin() + target);
		return password;
	}
};
int main() {
	string test = "s3cur1tyC0d3";
	Solution S;
	string res = S.dynamicPassword(test, 4);
	return 0;
}