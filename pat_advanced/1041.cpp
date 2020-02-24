#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
  int N;
  int num[10001] = {0};
  int temp[100001];
  cin >> N;
  int a;
  for (int i = 0; i < N;i++){
    cin >> a;
    num[a]++;
    temp[i] = a;
  }
  int i;
  for (i = 0; i < N;i++){
    if(num[temp[i]] == 1) {
      cout << temp[i];
      break;
    }
  }
  if(i == N){
    cout << "None";
  }
}