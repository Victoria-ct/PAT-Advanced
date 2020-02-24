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

const int maxN = 510;
const int INF = 100000000;
int G[maxN][maxN] = {{INF}};
int d[maxN];  //最短距离
int w[maxN]; //点权
int vis[maxN] = {false};
int num[maxN],rel[maxN];
int N, M, C1, C2;

void dij(int C1){
  fill(d, d + maxN, INF);
  memset(num, 0, sizeof(num));
  memset(rel, 0, sizeof(rel));
  d[C1] = 0;
  rel[C1] = w[C1];
  num[C1] = 1;
  for (int i = 0; i < N;i++){
    int u = -1, MIN = INF;
    for (int j = 0; j < N; j++){
      if(vis[j] == false && d[j] < MIN){
        u = j;
        MIN = d[j];
      }
    }
    if (u == -1)
      return;
    vis[u] = true;
    for (int v = 0; v < N; v++){
        if(vis[v] == false && G[u][v] != INF){
          if(d[u] + G[u][v] < d[v]){
            d[v] = d[u] + G[u][v];
            rel[v] = rel[u] + w[v];
            num[v] = num[u];
          } else if(d[u] + G[u][v] == d[v]){
              if(rel[u] + w[v] > rel[v]){
                rel[v] = rel[u] + w[v];
              }
              num[v] += num[u];
          }
        }
    }
  }
}
int main(){
  cin >> N >> M >> C1 >> C2;
  fill(G[0],G[0] + maxN * maxN,INF);
  for (int i = 0; i < N;i++){
    cin >> w[i];
  }
  for (int i = 0; i < M; i++){
    int c1, c2, L;
    cin >> c1 >> c2 >> L;
    G[c1][c2] = G[c2][c1] = L;
  }
  dij(C1);
  cout << num[C2] << " " << rel[C2];
  return 0;
}

  