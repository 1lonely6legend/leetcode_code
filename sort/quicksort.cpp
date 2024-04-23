//
// Created by ogier on 24-4-23.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//快速排序
int Partition_Hoare(vector<int> &arr, int left, int right) {
  int i = left;
  int j = right;
  int key = arr[left];
  while (i != j) {
    while (i < j && arr[j] >= key)
      j--;
    while (i < j && arr[i] <= key)
      i++;
    swap(arr[i], arr[j]);
  }
  swap(arr[left], arr[i]);
  return i;
}
void quick_sort(vector<int> &a, int left, int right) {
  if (left > right)
    return;
  int i = Partition_Hoare(a, left, right);
  quick_sort(a, left, i - 1);
  quick_sort(a, i + 1, right);
  return;
}

int main() {
  vector<int> raw = {1, 5, 2, 23, 4, 5, 25, 57, 745, 32, 13, 4};
  quick_sort(raw, 0, raw.size() - 1);
  for (auto i : raw)
    cout << i << " ";
  return 0;
}