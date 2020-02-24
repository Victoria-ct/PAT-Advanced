#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int N,ls = 0,cs,result = 0;
  cin >> N;
  for(int i =0;i<N;i++){
    cin >> cs;
    if (cs > ls) {
      result += (cs-ls)*6;
    } else {
      result += (ls-cs)*4;
    }
    result += 5;
    ls = cs;
  }
  cout << result;
  return 0;
}
  