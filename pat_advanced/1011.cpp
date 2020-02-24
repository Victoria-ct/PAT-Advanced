#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  double sum = 1, maxodd = 0,odd = 0;
  int max = 0;
  char result[3] = {'W','T','L'};
  for (int i = 0; i < 3; i++){
    maxodd = 0;
    for (int j = 0; j < 3; j++){
      cin >> odd;
      if (maxodd < odd) {
        maxodd = odd;
        max = j;
      }
    }
    sum *= maxodd;
    printf("%c ", result[max]);
  }
  printf("%.2lf", (sum * 0.65 - 1) * 2);
  return 0;
}
  