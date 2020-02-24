#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N, b;
  cin >> N >> b;
  vector<int> a;
  int temp = N;
  while(N != 0){
    a.push_back(N % b);
    N /= b;
  }
  int flag = 1, j = a.size() - 1;
  for (int i = 0; i < a.size(); i++){
    if(a[i] != a[j]){
      flag = 0;
    }
    j--;
  }
  if(flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  if(temp == 0){
    cout << 0;
  }
  for (int i = a.size() - 1; i >= 0; i--){
    cout << a[i];
    if(i != 0)
      cout << " ";
  }
    return 0;
}