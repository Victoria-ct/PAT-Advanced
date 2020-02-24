#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int, double> po,por;
int main(){
  int K;
  int ex;
  double co;
  cin >> K;
  for (int i = 0; i < K; i++){
    cin >> ex >> co;
    po[ex] = co;
  }
  cin >> K;
  int tempex;
  double tempco;
  for (int i = 0; i < K; i++){
    cin >> ex >> co;
    for (map<int, double>::iterator it = po.begin(); it != po.end(); it++){
      tempex = ex + it->first;
      tempco = co * it->second;
      if(por.count(tempex)){
        por[tempex] += tempco;
      } else {
        por[tempex] = tempco;
      }
    }
  }
  int count = 0;
  for (map<int, double>::reverse_iterator it = por.rbegin(); it!= por.rend();it++){
    if(it->second != 0.0)
      count++;    
  }
  cout << count;
  for (map<int, double>::reverse_iterator it = por.rbegin(); it != por.rend(); it++){
    if(it->second != 0.0)
    printf(" %d %.1lf", it->first, it->second);
  }
  
  return 0;
}
  