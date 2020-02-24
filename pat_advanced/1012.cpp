#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
struct ranks{
  int c;
  int m;
  int e;
  int a;
  int rank = 9999999;
  int tempRank;
  string course,ID;
  ranks() : c(0), m(0), e(0), a(0), course(""),ID(""){};
};
bool cmpC(ranks a, ranks b){
  if(a.c > b.c)
    return true;
  else
    return false;
}
bool cmpM(ranks a, ranks b){
  if(a.m > b.m)
    return true;
  else
    return false;
}
bool cmpE(ranks a, ranks b){
  if(a.e > b.e)
    return true;
  else
    return false;
}
bool cmpA(ranks a, ranks b){
  if(a.a > b.a)
    return true;
  else
    return false;
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<ranks> stu(N);
  map<string, ranks> re;
  map<char, int> sy;
  for (int i = 0; i < N;i++){
    cin >> stu[i].ID >> stu[i].c >> stu[i].m >> stu[i].e;
    stu[i].a = stu[i].c + stu[i].m + stu[i].e;
  }
  // A > C > M > E
  sort(stu.begin(), stu.end(), cmpA);
  for (int i = 0; i < N; i++){
    if(i == 0)
      stu[i].tempRank = 1;
    else if (stu[i].a == stu[i - 1].a){
      stu[i].tempRank = stu[i - 1].tempRank;
    } else {
      stu[i].tempRank = i + 1;
    }
    if(stu[i].rank > stu[i].tempRank){
      stu[i].rank = stu[i].tempRank;
      stu[i].course = "A";
    }
  }

  sort(stu.begin(), stu.end(), cmpC);
  for (int i = 0; i < N; i++){
    if(i == 0)
      stu[i].tempRank = 1;
    else if (stu[i].c == stu[i - 1].c){
      stu[i].tempRank = stu[i - 1].tempRank;
    } else {
      stu[i].tempRank = i + 1;
    }
    if(stu[i].rank > stu[i].tempRank){
      stu[i].rank = stu[i].tempRank;
      stu[i].course = "C";
    }
  }

  sort(stu.begin(), stu.end(), cmpM);
  for (int i = 0; i < N; i++){
    if(i == 0)
      stu[i].tempRank = 1;
    else if (stu[i].m == stu[i - 1].m){
      stu[i].tempRank = stu[i - 1].tempRank;
    } else {
      stu[i].tempRank = i + 1;
    }
    if(stu[i].rank > stu[i].tempRank){
      stu[i].rank = stu[i].tempRank;
      stu[i].course = "M";
    }
  }

  sort(stu.begin(), stu.end(), cmpE);
  for (int i = 0; i < N; i++){
    if(i == 0)
      stu[i].tempRank = 1;
    else if (stu[i].e == stu[i - 1].e){
      stu[i].tempRank = stu[i - 1].tempRank;
    } else {
      stu[i].tempRank = i + 1;
    }
    if(stu[i].rank > stu[i].tempRank){
      stu[i].rank = stu[i].tempRank;
      stu[i].course = "E";
    }
  }

  for (int i = 0; i < N; i++){
    re[stu[i].ID] = stu[i];
  }
  for (int i = 0; i < M; i++){
    string ID;
    cin >> ID;
    if(re.find(ID) == re.end()){
      cout << "N/A" << endl;
    } else{
      cout << re[ID].rank << " " << re[ID].course << endl;
    }
  }
}
  