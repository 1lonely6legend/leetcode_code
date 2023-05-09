//
// Created by ogier on 2023/5/8.
// 134. 加油站 md
#include <iostream>
#include <vector>
using std::vector;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int size = gas.size();
  for (int i = 0; i < size; ++i) {
    gas[i] -= cost[i];
  }
  int start = 0;
  int gas_tank = 0;
  int i;
  while (start < size && gas[start % size] < 0)
    ++start;
  while (start < size) {
    for (i = start; i < start + size; ++i) {
      gas_tank += gas[i % size];
      if (gas_tank < 0) break;
    }
    if (gas_tank < 0) {
      start = i;
      gas_tank = 0;
    } else {
      return start;
    }
    while (start < size && gas[start % size] < 0)
      ++start;
  }
  return -1;
}
int main() {
  vector<int> gas = {5, 1, 2, 3, 4};
  vector<int> cost = {4, 4, 1, 5, 1};
//  vector<int> gas = {1, 2, 3, 4, 5};
//  vector<int> cost = {3, 4, 5, 1, 2};
//  vector<int> gas = {2, 3, 4};
//  vector<int> cost = {3, 4, 3};
//  vector<int> gas = {4};
//  vector<int> cost = {5};
  std::cout << canCompleteCircuit(gas, cost) << std::endl;
  return 0;
}

