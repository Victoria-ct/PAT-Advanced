#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int isPalin(string n){
  int i;
  for (i = 0; i <= (n.length() + 1) /2; i++){
    if(n[i] != n[n.length() - 1 - i]){
      break;
    }
  }
  if(i > (n.length() + 1) /2){
    return 1;
  } else{
    return 0;
  }
}
int main(){
  string N;
  int K;
  cin >> N >> K;
  int i;
  string stemp = N;
  for (i = 0; i < K; i++){
    if (isPalin(stemp)){
      cout << stemp << endl;
      cout << i << endl;
      break;
    } else{
      int j,flag = 0;
      string str;
      for (j = 0; j < stemp.length(); j++){
        int temp = (stemp[j] - '0') + (stemp[stemp.length() - j - 1] - '0') + flag;
        flag = temp >= 10 ? 1 : 0;
        str = to_string(temp % 10) + str;
      }
      if (flag == 1){
        str = "1" + str;
      }
      stemp = str;
    }
  }
  if (i == K){
    cout << stemp << endl;
    cout << K << endl;
  }
  return 0;
}