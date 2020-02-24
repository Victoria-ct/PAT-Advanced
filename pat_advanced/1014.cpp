#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct win{
  int num = 0; //窗口人数
  queue<int> q;
  int m = 480;      //空闲时间
};
int main(){
  int N, M, K, Q;
  cin >> N >> M >> K >> Q;
  vector<win> win(N);
  vector<int> rel(K + 1);
  vector<int> cust(K + 1);
  for (int i = 1; i <= K;i++){
    cin >> cust[i];
    if (i <= N * M){
      // 找队伍最短的窗口
      int j, min = 0;
      for (j = 0; j < N; j++){
        if(win[j].num < win[min].num){
          min = j;
        }
      }
      win[min].num ++;
      win[min].m += cust[i];
      rel[i] = win[min].m;
      win[min].q.push(win[min].m);
    }

    // 没有窗口空闲,没法进黄线，找第一个离开的顾客属于哪个窗口
    if (i > N * M){
      int min = 0;
      for (int j = 0; j < N; j++){
        int fc = win[j].q.front();  //每个窗口第一个顾客
        if(fc < win[min].q.front()){
          min = j;
        }
      }
      win[min].q.pop();
      win[min].m += cust[i];
      rel[i] = win[min].m;
      win[min].q.push(win[min].m);
    }
  }
  for (int i = 0; i < Q; i++){
    int ID;
    cin >> ID;
    int h = rel[ID] / 60;
    int m = rel[ID] % 60;
    if(rel[ID] - cust[ID] >= 17 * 60){
      printf("Sorry\n");
    } else{
      printf("%02d:%02d\n",h,m);
    }
  }
    return 0;
  }

  