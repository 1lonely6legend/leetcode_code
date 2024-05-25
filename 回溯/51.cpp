//
// Created by ogier on 24-5-15.
//
#include <functional>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  static bool mizi_test(vector<string> &map, int row, int col) {
    //米字路线上有q时，返回true
    int size = map.size();
    //这里直接设置好八个方向的移动
    vector<array<int, 2>> moves = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto move : moves) {//遍历八个方向如果，在map范围内，判断是否等于Q
      int nx = row;
      int ny = col;//每次都要初始化为当前的位置
      while (true) {
        nx +=  move[0];
        ny +=  move[1];//每次都要加上移动的距离
        if (nx < 0 || nx >= size || ny < 0 || ny >= size) {
          break;//这里是||,当越界时，直接break
        }
        if (map[nx][ny] == 'Q') return true;//如果当前遇到了Q，返回true
      }
    }
    return false;
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> map(n, string(n, '.'));//初始化好n*n的map，用.填充
    function<void(int)> dfs = [&](int row) {
      if (row == n) {//这里应该设置为n，而不是n-1，因为最后递归到最后一行之后，再加一，这时候row=n，就是n行了
        res.emplace_back(map);
        return;
      }
      for (int i = 0; i < n; ++i) {
        //这里就是一个简单的回溯，如果当前位置可以放Q，就放上Q，然后递归下一行，如果不能放，就继续下一个位置
        if (mizi_test(map, row, i)) continue;
        map[row][i] = 'Q';
        dfs(row + 1);
        map[row][i] = '.';
      }
    };
    dfs(0);
    return res;
  }
};