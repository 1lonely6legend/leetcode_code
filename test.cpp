//
// Created by ogier on 2023/10/13.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
  vector<int> test = {1, 2, 3, 4, 5, 6};
  vector<int> test2(test.begin(), test.begin()+1);
  for (auto iter = test2.begin(); iter != test2.end(); iter++) {
    cout << *iter << " ";
  }
  return 0;
}