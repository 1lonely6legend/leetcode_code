//
// Created by ogier on 24-4-23.
// 插入排序，分为两部分，排序好的和没排序的，相当于扑克牌抓牌，每次从未排序中拿出一个，插入到有序部分中
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//插入排序
template<size_t N>
void insertion_sort(int (&a)[N]) {
  for (int i = 1; i < N; ++i) {
    //拿出当前未排序的元素
    int key = a[i];
    //找到当前元素的前一个元素，从后往前找插入位置
    int j = i - 1;
    //从后往前找到第一个比key小的元素，然后将key插入到这个元素的后面
    while (j >= 0 && a[j] > key) {
      //将元素往后移动
      a[j + 1] = a[j];
      j--;
    }
    //插入元素
    a[j + 1] = key;
  }
}
//选择排序
template<size_t N>
void select_sort(int (&a)[N]) {
  for (int i = 0; i < N; ++i) {
    int min = i;
    for (int j = i + 1; j < N; ++j) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
  }
}
//冒泡排序
template<size_t N>
void pop_sort(int (&a)[N]) {
  int n = N;
  while (n) {
    for (int i = 0; i < N - 1; ++i) {
      if (a[i] > a[i + 1]) {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
      }
    }
    n--;
  }
}
//计数排序，使用多余空间，一个记录每个数字出现的次数，一个记录每个数字出现的位置，适用于元素种类不多的情况
void calculate_num_sort(vector<int> &arr) {
  int size = arr.size();
  if (size == 1) return;
  int max = arr[0];
  for (auto &num : arr) {
    if (num > max) max = num;
  }
  vector<int> count(max + 1, 0);
  vector<int> tmp(arr);
  for (auto &x : arr) {
    //首先计算每个数字出现的次数
    count[x]++;
  }
  for (int i = 1; i <= max; ++i) {
    //然后计算每个数字出现的位置
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; --i) {
    //根据位置将数字放到对应的位置，这里需要注意的是，位置是从1开始的，所以需要减1
    arr[count[tmp[i]] - 1] = tmp[i];
    //每次放完一个数字，位置减1，这样下次相同的数字就会放到前一个位置
    count[tmp[i]]--;
  }
}

//快速排序
void quick_sort(vector<int> &arr, int left, int right) {
  int i = left;
  int j = right;
  int key = arr[left];
  while (i != j) {
    while (i < j && a[j] >= key)
      j--;
    while (i < j && a[i] <= key)
      i++;
    swap(arr[i], arr[j]);
  }
  swap(arr[left],arr[i]);
}

int main() {
  int a[] = {3, 5, 6, 536, 236, 25, 25, 2, 5, 4545, 66, 7, 34353};
  insertion_sort(a);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}