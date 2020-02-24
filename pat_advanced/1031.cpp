#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string n;
  cin >> n;
  int N = n.length();
  int n1, n2,k;
  for (int i = 3; i <= N; i++){
    if ((N + 2 -i) %2 == 0){
      k = (N + 2 - i) / 2;
    }else{
      continue;
    }
    if (k > i){
      continue;
    } else{
      n1 = k, n2 = i;
      break;
    }
  }
  for (int j = 0; j < n1; j++){
    printf("%c", n[j]);
    for (int i = 0; i < n2 - 2; i++){
      if(j + 1 == n1)
        printf("%c", n[n1 + i]);
      else
        printf(" ");
    }
    printf("%c", n[N - j - 1]);
    printf("\n");
  }
    return 0;
}