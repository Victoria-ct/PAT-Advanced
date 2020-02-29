#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main() {
  int b, s1 = 0, s2 = 0;
  string str1, str2, str3 = "", str4 = "";
  cin >> b >> str1 >> str2;
  int l1 = str1.find('.') == -1 ? str1.length() : str1.find('.');
  int l2 = str2.find('.') == -1 ? str2.length() : str2.find('.');
  if (b >= 100 || str1.length() - l1 > 100 || str2.length() - l1 > 100){
    return 0;
  }
  for (int i = 0; i < str1.length(); i++){
    if(str1[i] != '0' && str1[i]!= '.'){
      if (i > l1){
        s1 = -1 * (i - l1 - 1);
      } else {
        s1 = l1 - i;
      }
      for (int j = i; str3.length() < b && j < str1.length(); j++){
        if (str1[j] != '.'){
          str3 += str1[j];
        }
      }
      break;
    } 
  }
  for (int i = 0; i < str2.length(); i++){
    if(str2[i] != '0' && str2[i]!= '.'){
      if (i > l2){
        s2 = -1 * (i - l2 - 1);
      } else {
        s2 = l2 - i;
      }
      for (int j = i; str4.length() < b && j < str2.length(); j++){
        if (str2[j] != '.'){
          str4 += str2[j];
        }
      }
      break;
    } 
  }
  // 如果str3与str4的长度小于b，补充0
  if (str3.length() < b) {
    int k = b - str3.length();
    for (int i = 0; i < k; i++){
      str3 += '0';
    }
  }
  if (str4.length() < b) {
     int k = b - str4.length();
    for (int i = 0; i < k; i++){
      str4 += '0';
    }
  }
  if (str3 == str4 && s1 == s2) {
    cout << "YES 0." << str3 << "*10^" << s1 << endl;
  } else {
    cout << "NO 0." << str3 << "*10^" << s1 << " 0." << str4 << "*10^" << s2 << endl;
  }
  return 0;
}
