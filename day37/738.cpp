#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int monotoneIncreasingDigits(int n) {
    string num = to_string(n);
    // 使用flag标记9的替换从哪里开始
    int flag = num.size();
    for (int i = num.size() - 1; i > 0; --i) {
      if (num[i - 1] > num[i]) {
        flag = i;
        num[i - 1]--;
      }
    }
    for (int i = flag; i < num.size(); ++i) {
      num[i] = '9';
    }
    return stoi(num);
  }
};