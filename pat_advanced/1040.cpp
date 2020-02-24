#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int dp[1001][1001];
int main(){
  string str;
  getline(cin, str);
  int rel = 1;
  memset(dp, 0,sizeof(dp));
  for (int i = 0; i < str.length();i++){
    dp[i][i] = 1;
    if (i < str.length() - 1 && str[i] == str[i+1]){
      dp[i][i+1] = 1;
      rel = 2;
    }
  }
  for (int L = 3; L <= str.length();L++){
    for (int i = 0; i <= str.length() - L;i++){
      if (str[i] == str[i + L -1] && dp[i+1][i+L-2]){
        dp[i][i + L - 1] = 1;
        rel = L;
      }
    }
  }
  cout << rel;
  return 0;
}