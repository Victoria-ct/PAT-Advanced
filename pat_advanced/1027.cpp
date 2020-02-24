#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main(){
  char radix13[3] = {'A','B','C'};
  string result = "#";
  for (int i = 0; i < 3; i++){
    int sum = 0;
    cin >> sum;
    string temp = "";
    if (sum == 0){
      temp = '0';
    }
    while(sum != 0) {
      if (sum % 13 >= 10) {
        temp = radix13[sum% 13 - 10] + temp;
      } else {
        temp = to_string(sum % 13) + temp;
      }
      sum /= 13;
    }
    if (temp.length() == 1) {
      temp = '0' + temp;
    }
    result += temp;
  }
  cout << result;
  return 0;
}