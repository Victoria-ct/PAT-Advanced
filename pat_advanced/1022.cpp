#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
map<string, set<string>> tit,aut,key,pub,y;

void search(map<string, set<string>> &b, string name){
  if (b.find(name) == b.end()){
    cout << "Not Found" << endl;
  } else{
    for (set<string>::iterator it = b[name].begin(); it != b[name].end(); it++){
      cout << *it << endl;
    }
  }
}
int main(){
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++){
    string ID;
    string title,keyword,author,publisher,year;
    getline(cin, ID);
    getline(cin, title);
    tit[title].insert(ID);
    getline(cin, author);
    aut[author].insert(ID);
    while(cin >> keyword){
      key[keyword].insert(ID);
      char c = getchar();
      if (c == '\n')
        break;
    }
    getline(cin, publisher);
    pub[publisher].insert(ID);
    getline(cin, year);
    y[year].insert(ID);
  }
  int M;
  cin >> M;
  for (int i = 0; i < M;i++){
    int id;
    string name;
    scanf("%d: ",&id);
    getline(cin, name);
    cout << id << ": " << name << endl;
    if(id == 1){
      search(tit, name);
    }
    if(id == 2){
      search(aut, name);
    }
    if(id == 3){
      search(key, name);
    }
    if(id == 4){
      search(pub, name);
    }
    if(id == 5){
      search(y, name);
    }
  }
    return 0;
}