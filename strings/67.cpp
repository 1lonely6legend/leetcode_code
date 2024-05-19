//
// Created by ogier on 24-5-19.
//
class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int loop = max(a.size(),b.size());
    int carry = 0;
    string res;
    for(int i = 0; i < loop; ++i){
      int num1, num2;
      if(i >= a.size()){
        num1 = 0;
      }else{
        num1 = (a[i] == '0') ? 0 : 1;
      }
      if(i >= b.size()){
        num2 = 0;
      }else{
        num2 = (b[i] == '0') ? 0 : 1;
      }
      int sum = num1 + num2 + carry;
      res.push_back(sum%2 + '0');
      carry = sum / 2;
    }
    if(carry > 0){
      res.push_back('1');
    }
    reverse(res.begin(),res.end());
    return res;
  }
};