#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int A1,A2,A3,B1,B2,B3;
  scanf("%d.%d.%d %d.%d.%d", &A1, &A2, &A3, &B1, &B2, &B3);
  printf("%d.%d.%d", A1 + B1 + (A2 + B2 + (A3 + B3) / 29) / 17, (A2 + B2 + (A3 + B3) / 29) % 17, (A3 + B3) % 29);
  return 0;
}