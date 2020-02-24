#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
map<int, double> po,por;
int main(){
  string N1, N2;
  int tag, radix;
  cin >> N1 >> N2 >> tag >> radix;
  string temp = tag == 1 ? N1 : N2;
  string temp2 = tag == 1 ? N2 : N1;
  long long sum = 0;
  // temp转化为十进制
  for (int i = 0; i < temp.length();i++){
    if (temp[i] >= 'a' && temp[i] <= 'z')
      temp[i] = 10 + temp[i] - 'a';
    else
      temp[i] = temp[i] - '0';
    sum += pow(radix, temp.length() - i - 1) * temp[i];
  }
  // temp2转化10进制，与sum比较
  long long sum2 = 0;
  long long radixtemp = -1;
  char it = *max_element(temp2.begin(), temp2.end());
  long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
  long long high = max(low, sum);
  while (low <= high) {
    sum2 = 0;
    long long mid = (low + high) / 2;
    for (int i = 0; i < temp2.length();i++){
      if (temp2[i] >= 'a' && temp2[i] <= 'z')
        sum2 += pow(mid, temp2.length() - i - 1) * (10 + temp2[i] - 'a');
      else
        sum2 += pow(mid, temp2.length() - i - 1) * (temp2[i] - '0');
    }
    if (sum2 < 0 || sum2 > sum) {
      high = mid - 1;
    } else if (sum2 < sum){
      low = mid + 1;
    } else {
      radixtemp = mid;
      break;
    }
  }
  if (radixtemp == -1){
    cout << "Impossible";
  } else {
    cout << radixtemp;
  }
  return 0;
}
  