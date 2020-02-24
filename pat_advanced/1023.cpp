#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string n,m;
  int a[11] = {0}, b[11] = {0};
  cin >> n;
  int flag = 0;
  for (int i = n.length() - 1; i >= 0;i--){
    int temp = n[i] - '0';
    a[temp]++;
    temp = temp * 2 + flag;
    if (temp >= 10){
      flag = 1;
      temp = temp % 10;
    } else {
      flag = 0;
    }
    b[temp]++;
    m = to_string(temp) + m;
  }
  if (flag == 1) {  // 第一位如果大于10，进位
    b[1]++;
    m = "1" + m;
  }
  int j;
  for (j = 0; j < 10;j++){
    if (b[j] != a[j]){
      cout << "No" << endl;
      break;
    }
  }
  if (j == 10){
    cout << "Yes" << endl;
  }
  cout << m;
}