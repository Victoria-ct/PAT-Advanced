#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

struct card{
  string ID;
  int grade;
};

int cmp(card a, card b){
  if (a.grade > b.grade)
    return 1;
  else if (a.grade == b.grade && a.ID < b.ID)
    return 1;
  else
    return 0;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<card> cards(N);

  for (int i = 0; i < N; i++){
    string ID;
    int grade;
    cin >> ID >> grade;
    cards[i].ID = ID;
    cards[i].grade = grade;
  }
  for (int i = 0; i < M; i++){
    int type;
    string term;
    vector<card> t1_3;
    cin >> type >> term;
    printf("Case %d: %d %s\n", i + 1, type, term.c_str());
    int flag = 0;
    if (type == 1){
      for (int j = 0; j < N; j++){
        if (cards[j].ID[0] == term[0]){
          flag = 1;
          t1_3.push_back(cards[j]);
        }
      }
    } else if (type == 2){
      int num = 0, sum = 0;
      for (int j = 0; j < N; j++){
        if (cards[j].ID.substr(1,3) == term){
          flag = 1;
          num++;
          sum += cards[j].grade;
        }
      }
      if (num > 0)
        printf("%d %d\n", num, sum);
    } else if (type == 3){
       unordered_map<string, int> type3;
       for (int j = 0; j < N; j++){
         if (cards[j].ID.substr(4,6) == term){
            flag = 1;
            type3[cards[j].ID.substr(1,3)]++;
          }
       }
       // 将map改为vector,并排序
       for (unordered_map<string, int>::iterator it = type3.begin(); it != type3.end(); it++){
         t1_3.push_back({it->first, it->second});
       }
    }
    sort(t1_3.begin(), t1_3.end(), cmp);
    for (int j = 0; j < t1_3.size(); j++)
      printf("%s %d\n", t1_3[j].ID.c_str(), t1_3[j].grade);

    if(flag == 0)
      printf("NA\n");
    }
    return 0;
}