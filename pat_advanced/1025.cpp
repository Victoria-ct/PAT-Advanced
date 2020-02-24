#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct reg{
  string rn;
  int score, ln,lr,fr;
  reg(string _rn, int _score,int _ln) : rn(_rn), score(_score), ln(_ln){}
};

int bmp(reg a, reg b){
  if(a.score > b.score)
    return 1;
  else if (a.score == b.score && a.rn < b.rn)
    return 1;
  else
    return 0;
}
int main(){
  vector<reg> testees;
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 1; i <= N; i++){
    int num;
    cin >> num;
    if (num == 0)
      continue;
    for (int j = 0; j < num;j++){
      string rn;
      int score;
      cin >> rn >> score;
      testees.push_back(reg(rn, score, i));
    }
    sort(testees.begin() + sum, testees.begin() + sum + num, bmp);
    testees[sum].lr = 1;
    int q = 1;
    for (int z = sum + 1; z < sum + num; z++){
      if(testees[z].score == testees[z-1].score){
        testees[z].lr = testees[z - 1].lr;
      } else{
        testees[z].lr = q + 1;
      }
      q++;
    }
    sum += num;
  }
  sort(testees.begin(), testees.end(), bmp);
  cout << testees.size() << endl;
  for (int i = 0; i < testees.size();i++){
    if(i == 0){
      testees[i].fr = 1;
    } else if(testees[i].score == testees[i - 1].score){
      testees[i].fr = testees[i - 1].fr;
    } else{
      testees[i].fr = i + 1;
    }
    cout << testees[i].rn << " " << testees[i].fr << " " <<testees[i].ln << " " <<testees[i].lr << endl;
  }
    return 0;
}