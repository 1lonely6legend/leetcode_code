//
// Created by ogier on 24-5-14.
// 也就是判断这个图是不是有环，如果有环就不能完成所有课程
#include <vector>
#include <queue>
using namespace std;
class Solution {
  private:
    vector<vector<int> > edges;
    vector<int> indeg;

  public:
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
      edges.resize(numCourses);
      indeg.resize(numCourses);
      for (const auto &info : prerequisites) {
        edges[info[1]].push_back(info[0]);
        ++indeg[info[0]];
      }

      queue<int> q;
      for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
          q.push(i);
        }
      }

      int visited = 0;
      while (!q.empty()) {
        ++visited;
        int u = q.front();
        q.pop();
        for (int v : edges[u]) {
          --indeg[v];
          if (indeg[v] == 0) {
            q.push(v);
          }
        }
      }

      return visited == numCourses;
    }
};
