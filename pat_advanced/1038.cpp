#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int cmp(string a,string b){
  int i = 0, j = 0,cnt = 1;
  while(cnt <= 8){
    if (a[i] - '0' < b[j] - '0')
      return 1;
    else if (a[i] - '0' > b[j] - '0')
      return 0;
    else if (a[i] - '0' == b[j] - '0'){
      i++, j++;
      if (i == a.length() && j == b.length()){
        return 1;
      }
      if (i == a.length())
        i = 0;
      else if(j == b.length())
        j = 0;
    }
    cnt++;
  }
  return 1;
}
int main(){
  int N;
  cin >> N;
  vector<string> nums(N);
  for (int i = 0; i < N; i++){
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end(), cmp);
  int flag = 0;
  for (int i = 0; i < nums.size(); i++){
    for (int j = 0; j < nums[i].length();j++){
      if(nums[i][j] != '0'){
        flag = 1;
      }
      if (!flag){
        continue;
      }
      cout << nums[i][j];
    }
  }
  if (flag == 0){
    cout << 0;
  }
  return 0;
}