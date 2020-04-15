#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct node {
  char data;
  int next;
  int flag = 0;
};

int main(){
  int a1, a2, N;
  cin >> a1 >> a2 >> N;
  vector<node> words(100000);
  for (int i = 0; i < N;i++){
    int a, next;
    char data;
    cin >> a >> data >> next;
    words[a].data = data;
    words[a].next = next;
  }
  for (int i = a1; i != -1; i = words[i].next){
    words[i].flag = 1;
  }
  int i;
  for (i = a2; i != -1; i = words[i].next){
    if(words[i].flag){
      printf("%05d", i);
      break;
    }
  }
  if (i == -1){
    printf("-1");
  }
  
  return 0;
}