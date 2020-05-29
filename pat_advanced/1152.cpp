#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int isPrime(int a){
  if (a == 1 || a== 0)
    return 0;
  for (int i = 2; i * i <= a; i++){
    if (a % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int L, K;
  cin >> L >> K;
  char a[L + 1];
  int left = 1, right = K;
  int i;
  for (i = 1; i <= L; i++){
    cin >> a[i];
    if (i >= K){
      int sum = 0, bit = 1;
      for (int z = right; z >= left; z--){
        sum += ((a[z] - '0') * bit);
        bit *= 10;
      }
      if (isPrime(sum)){
        for (int z = left; z <= right; z++){
          printf("%c", a[z]);
        }
        break;
      }
      left++;
      right++;
    }

  }
  if (i > L){
    printf("404");
  }
  return 0;
}
  