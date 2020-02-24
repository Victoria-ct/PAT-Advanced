#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxN = 1001;
vector<int> Adj[maxN];
int N, M, K;
bool vis[maxN] = {false};

void DFS(int e){
  vis[e] = true;
  for (int i = 0; i < Adj[e].size(); i++){
    if(vis[Adj[e][i]] == false){
      DFS(Adj[e][i]);
    }
  }
}
int DFStraver(){ 
  int num = 0; // 连通块数量
  for (int i = 1; i <= N; i++){
    if(vis[i] == false){
      num++;
      DFS(i);
    }
  }
  return num;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  for (int i = 0; i < M; i++){
    int c1, c2;
    cin >> c1 >> c2;
    Adj[c1].push_back(c2);
    Adj[c2].push_back(c1);
  }
  for (int i = 0; i < K; i++){
    memset(vis, false, N + 1);
    int c;
    cin >> c;
    vis[c] = true;
    cout << DFStraver() - 1 << endl;
  }
  return 0;
}

  