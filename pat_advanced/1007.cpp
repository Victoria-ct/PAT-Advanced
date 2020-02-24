#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct result {
  int f, e,sum;
} result, temp;
int main(){
  int M;
  cin >> M;
  vector<int> a(M);
  for (int i =0;i<M;i++){
    cin >> a[i];
    temp.sum += a[i];
    if (i ==0){
      temp.e = temp.f = i;
      result = temp;
    }
    if (temp.sum < a[i]){
      temp.f = i;
      temp.sum = a[i];
    }
    if (temp.sum > result.sum) {
      temp.e = i;
      result = temp;
    }
  }
  if (result.sum < 0) {
    cout << 0 << " " << a[0] << " " << a[M -1];
  } else {
    cout << result.sum << " " << a[result.f] << " " << a[result.e];
  }
  return 0;
}
