#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct record{
  string ID,name;
  int grade;
};
bool cmp1(record a,record b){
  return a.ID < b.ID ? true : false;
}
bool cmp2(record a,record b){
  return a.name == b.name ? a.ID < b.ID : a.name < b.name;
}
bool cmp3(record a,record b){
  return a.grade == b.grade ? a.ID < b.ID : a.grade < b.grade;
}
int main(){
  int N, C;
  cin >> N >> C;
  vector<record> records(N);
  for (int i = 0; i < N;i++){
    cin >> records[i].ID >> records[i].name >> records[i].grade;
  }
  if(C == 1)
    sort(records.begin(), records.end(), cmp1);
  else if(C == 2)
    sort(records.begin(), records.end(), cmp2);
  else if(C == 3)
    sort(records.begin(), records.end(), cmp3);
  for (int i = 0; i < N; i++){
    cout << records[i].ID << " " << records[i].name << " " << records[i].grade << endl;
  }
    return 0;
}