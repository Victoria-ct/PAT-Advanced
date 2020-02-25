#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
  string S1, S2,result;
  getline(cin, S1);
  getline(cin, S2);
  int hash[256] = {0};
  for (int i = 0; i < S2.length();i++){
    hash[S2[i]] = 1;
  }
  for (int i = 0; i < S1.length();i++){
    if (!hash[S1[i]]){
      result += S1[i];
    }
  }
  cout << result;
  return 0;
}
