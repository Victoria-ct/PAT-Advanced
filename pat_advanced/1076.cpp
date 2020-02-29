#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
const int MAXV = 1001;
int N, L;
vector<int> Adj[MAXV];
int M[MAXV];
void BFS(int u){
  bool inq[MAXV] = {false};
  queue<int> q;
  q.push(u);
  inq[u] = true;
  int level = 0;
  int num = 0 ; // 相连的顶点数
  int lnum = 0; // 每层的节点数
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for (int i = 0; i < Adj[u].size();i++){
      int v = Adj[u][i];
      if(inq[v] == false){
        q.push(v);
        num++;
        lnum++;
        inq[v] = true;
      }
    }
    if (lnum == q.size()){
      lnum = 0;
      level++;
    }
    if (level == L){
      break;
    }
  }
  printf("%d\n", num);
}
int main(){
  cin >> N >> L;
  for (int i = 1; i <= N;i++){
    cin >> M[i];
    for (int j = 0; j < M[i];j++){
      int temp;
      cin >> temp;
      Adj[temp].push_back(i);
    }
  }
  int K,k;
  cin >> K;
  for (int i = 0; i < K; i++){
    cin >> k;
    BFS(k);
  }
  return 0;
}
  