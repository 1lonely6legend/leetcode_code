//
// Created by ogier on 23-11-27.
// 134.加油站
#include <vector>
#include <climits>
using namespace std;
class SolutionForce {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    for (int i = 0; i < cost.size(); ++i) {
      int rest = gas[i] - cost[i];
      int index = (i + 1) % cost.size();
      while (rest > 0 && index != i) {
        rest += gas[index] - cost[index];
        index = (index + 1) % cost.size();
      }
      if (rest >= 0 && index == 1) return i;
    }
    return -1;
  }
};

class SolutionOne {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int min = INT_MAX;
    for (int i = 0; i < gas.size(); +i) {
      int rest = gas[i] - cost[i];
      curSum += rest;
      if (curSum < min) {
        min = curSum;
      }
    }
    if (curSum < 0) return -1;
    if (min >= 0) return 0;
    for (int i = gas.size() - 1; i >= 0; i--) {
      int rest = gas[i] - cost[i];
      min += rest;
      if (min >= 0)
        return i;
    }
    return -1;
  }
};

class SolutionTwo {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }
    if (totalSum < 0)return -1;
    return start;
  }
};

int main() {
  vector<int> test1 = {1, 2, 3, 4, 5};
  vector<int> test2 = {3, 4, 5, 1, 2};
  SolutionTwo S;
  auto res = S.canCompleteCircuit(test1, test2);
  return 0;
}