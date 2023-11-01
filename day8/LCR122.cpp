//
// Created by ogier on 2023/11/1.
// LCR122.路径加密
#include <string>
using namespace std;
class Solution {
 public:
	string pathEncryption(string path) {
		for (auto iter = path.begin(); iter != path.end(); iter++) {
			if (*iter == '.')
				*iter = ' ';
		}
		return path;
	}
};