//
// Created by ogier on 2023/12/22.
//
#include <vector>
#include <stack>
using namespace std;
class SolutionDoublePointer {
 public:
  int trap(vector<int> &height) {
    int size = height.size();
    if (size <= 2)
      return 0;
    vector<int> maxleft(size, 0);
    vector<int> maxright(size, 0);

    maxleft[0] = height[0];
    for (int i = 1; i < size; ++i) {
      maxleft[i] = max(height[i], maxleft[i - 1]);
    }

    maxright[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      maxright[i] = max(height[i], maxright[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < size; ++i) {
      int count = min(maxleft[i], maxright[i]) - height[i];
      if (count > 0)
        res += count;
    }
    return res;
  }
};

class SolutionMonotonicStack {
 public:
  int trap(vector<int> &height) {
    if (height.size() <= 2) return 0; // 可以不加
    stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
    st.push(0);
    int sum = 0;
    for (int i = 1; i < height.size(); i++) {
      if (height[i] < height[st.top()]) {     // 情况一
        st.push(i);
      }
      if (height[i] == height[st.top()]) {  // 情况二
        st.pop(); // 其实这一句可以不加，效果是一样的，但处理相同的情况的思路却变了。
        st.push(i);
      } else {                                // 情况三
        while (!st.empty() && height[i] > height[st.top()]) { // 注意这里是while
          int mid = st.top();
          st.pop();
          if (!st.empty()) {
            int h = min(height[st.top()], height[i]) - height[mid];
            int w = i - st.top() - 1; // 注意减一，只求中间宽度
            sum += h * w;
          }
        }
        st.push(i);
      }
    }
    return sum;
  }
};

int main(){
  SolutionMonotonicStack S;
  vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
  auto res = S.trap(test);
  return 0;
}
