#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int moves[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int BFS(vector<vector<bool>> &map, vector<vector<bool>> &visited, int i, int j) {
  int res = 1;
  visited[i][j] = true;
  queue<pair<int, int>> que;
  que.emplace(make_pair(i, j));
  while (!que.empty()) {
    auto cur = que.front();
    que.pop();
    for (auto &[di, dj] : moves) {
      int nexti = cur.first + di;
      int nextj = cur.second + dj;
      if (nexti >= 0 && nexti < map.size() && nextj >= 0 && nextj < map[0].size()) {
        if (!visited[nexti][nextj] && map[nexti][nextj]) {
          res++;
          visited[nexti][nextj] = true;
          que.emplace(make_pair(nexti, nextj));
        }
      }
    }
  }
  return res;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> map;
  for (int i = 0; i < N; ++i) {
    vector<bool> temp;
    for (int j = 0; j < M; ++j) {
      bool data;
      cin >> data;
      temp.emplace_back(data);
    }
    map.emplace_back(temp);
  }
  int res = INT_MIN;
  vector<vector<bool>> visited(N, vector<bool>(M, false));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (map[i][j] && !visited[i][j]) {
        res = max(BFS(map, visited, i, j), res);
      }
    }
  }
  res = (res == INT_MIN) ? 0 : res;
  cout << res;
  return 0;
}