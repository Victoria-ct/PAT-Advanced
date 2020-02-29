#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int main(){
  int M, N;
  cin >> M >> N;
  map<int, int> pixel;
  int data;
  int max = 0,rel = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      scanf("%d", &data);
      if(pixel.find(data) != pixel.end()){
        pixel[data]++;
      } else {
        pixel[data] = 1;
      }
      if(pixel[data] > max) {
        max = pixel[data];
        rel = data;
      }
    } 
  }
  printf("%d", rel);
  return 0;
}

  