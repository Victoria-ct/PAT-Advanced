#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main(){
  int N,sum = 0;
  scanf("%d",&N);
  vector<int> exit(N + 1);
  for (int i = 1; i <= N; i++){
    scanf("%d",&exit[i]);
    sum += exit[i];
  }
  int M;
  scanf("%d",&M);
  for (int i = 0; i < M; i++){
    int D1, D2, d1 = 0;
    scanf("%d %d",&D1,&D2);
    if (D1 < D2){
      for (int j = D1; j < D2; j++)
        d1 += exit[j];
    } else {
      for (int j = D2; j < D1; j++)
        d1 += exit[j];
      
    }
    if (d1 > sum - d1)
      printf("%d\n", sum - d1);
    else
      printf("%d\n", d1);
  }
    return 0;
}