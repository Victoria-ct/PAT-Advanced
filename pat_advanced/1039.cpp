#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
  int N, K;
  char name[5];
  unordered_map<string, vector<int>> stu;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; i++){
    int id, num;
    scanf("%d %d", &id, &num);
    for (int j = 0; j < num; j++){
        scanf("%s", name);
        stu[name].push_back(id);
    }
  }
  for (int i = 0; i < N; i++){
    scanf("%s", name);
    printf("%s %d", name,stu[name].size());
    sort(stu[name].begin(), stu[name].end());
    for (vector<int>::iterator it = stu[name].begin(); it != stu[name].end(); it++){
      printf(" %d", *it);
    }
    printf("\n");
  }
  return 0;
}
  