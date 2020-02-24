#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int isPrime(int a){
  if (a < 2){
    return 0;
  }
  for (int i = 2; i <= sqrt(a);i++){
    if (a % i == 0){
      return 0;
    }
  }
  return 1;
}
int main(){
  int N, D;
  cin >> N;
  vector<int> digits;
  while (N >= 0){
    cin >> D;
    int n = N;
    digits.clear();
    while (N != 0){
      digits.push_back(N % D);
      N /= D;
    }
    int sum = 0;
    for (int i = 0; i < digits.size(); i++){
      sum += (digits[i] * pow(D, digits.size() - i - 1));
    }
    if (isPrime(sum) && isPrime(n)){
        printf("Yes\n");
      } else {
      printf("No\n");
    }
    cin >> N;
  }
  return 0;
}