#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, double> po;
  int K,ex;
  double co;
  for (int i = 0;i<2;i++){
    cin >> K;
    for (int j = 0;j<K;j++){
      cin >> ex >> co;
      if (po.count(ex) == 0){
          po[ex] = co;
      } else {
        po[ex] += co;
      }
    }
  }
  int sum = 0;
  for (map<int, double>::iterator it = po.begin(); it != po.end(); it++){
    if(it->second != 0.0)
      sum ++;
  }
  printf("%d", sum);
  for (map<int, double>::reverse_iterator it = po.rbegin(); it != po.rend(); it++){
    if(it->second != 0.0){
      cout << " " << it -> first << " ";
      printf("%.1lf", it -> second);
    }
  }
  return 0;
}
