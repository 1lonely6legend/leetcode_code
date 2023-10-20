//
// Created by ogier on 2023/10/20.
//

//需注意测试数据不止一组，后续有单行数字代表又开始新的计算

#include <iostream>

int main() {
	int a, b, num;
	while (std::cin >> num) {
		while (num-- > 0) {
			std::cin >> a >> b;
			std::cout << a + b << std::endl;
		}
	}
	return 0;
}