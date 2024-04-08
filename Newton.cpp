//
// Created by ogier on 24-4-8.
//
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
double fd(double x) {
  //原始函数
  double c = (x * x * x) / 3 - x;
  //导数,也就是斜率
  double d = x * x - 1;
  //返回原始函数/斜率也就是横向截距
  return (c / d);
}

void newton(double x0, double e) {
  double a = x0;
  double x = x0 - fd(x0);
  int i = 0;
  while (abs(x - a) > e) {
    cout << a << endl;
    a = x;
    i++;
    x = x - fd(a);
      if(i>50){
        cout<<"迭代超过50次，失败"<<endl;
        return;
      }
  }
  cout<<"迭代次数为"<<i<<endl;
}

int main() {
  double x0, e;
  cout << "请输入x0的值：";
  cin >> x0;
  cout << "请输入容许误差：";
  cin >> e;
  newton(x0, e);
  return 0;
}