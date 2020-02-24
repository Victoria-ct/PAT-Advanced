#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1e9 + 10;
int main(){
  int N1,N2;
 
  scanf("%d", &N1);
   vector<long int> data1(N1 + 1);
  for (int i = 0; i < N1; i++){
    scanf("%ld", &data1[i]);
  }
  data1[N1] = INF;
  scanf("%d", &N2);
  vector<long int> data2(N2 + 1);
  for (int i = 0; i < N2; i++){
    scanf("%ld", &data2[i]);
  }
  data2[N2] = INF;
  int k = (N1 + N2 + 1) / 2 -1;
  int num = 0,i = 0,j = 0;
  while(num < k){
    if(data1[i]< data2[j])
      i++;
    else
      j++;
    num++;
  }
  int rel = data1[i] < data2[j] ? data1[i] : data2[j];
  printf("%ld", rel);
  return 0;
}