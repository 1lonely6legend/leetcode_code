//
// Created by ogier on 24-5-14.
//
#include <stack>
#include <climits>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
      stack<int> st;
      vector<int> res(temperatures.size(), 0);
      for (int i = temperatures.size() - 1; i >= 0; --i) {
        int t = temperatures[i];
        while (!st.empty() && t >= temperatures[st.top()]) {
          st.pop();
        }
        if (!st.empty()) {
          res[i] = st.top() - i;
        }
        st.push(i);
      }
      return res;
    }
};
int main() {
  vector<int> test = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
  Solution S;
  auto res = S.dailyTemperatures(test);
  return 0;
}
