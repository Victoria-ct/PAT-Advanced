#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int maxN = 510;
const int INF = 100000000;
int G[maxN][maxN] = {{INF}};
int C[maxN][maxN] = {{INF}};
int d[maxN];  //最短距离
int w[maxN]; //最少cost
int vis[maxN] = {false};
int pre[maxN];
int N, M, C1, C2;

void dij(int C1){
  fill(d, d + maxN, INF);
  d[C1] = 0;
  w[C1] = 0;
  pre[C1] = -1;
  for (int i = 0; i < N;i++){
    int u = -1, MIN = INF;
    for (int j = 0; j < N; j++){
      if(vis[j] == false && d[j] < MIN){
        u = j;
        MIN = d[j];
        // pre[j] = C1;
      }
    }
    if (u == -1)
      return;
    vis[u] = true;
    for (int v = 0; v < N; v++){
        if(vis[v] == false && G[u][v] != INF){
          if(d[u] + G[u][v] < d[v]){
            d[v] = d[u] + G[u][v];
            w[v] = w[u] + C[u][v];
            pre[v] = u;
          } else if(d[u] + G[u][v] == d[v]){
              if(w[u] + C[u][v] < w[v]){
                w[v] = w[u] + C[u][v];
                pre[v] = u;
              }
          }
        }
    }
  }
}
int main(){
  cin >> N >> M >> C1 >> C2;
  fill(G[0],G[0] + maxN * maxN,INF);
  for (int i = 0; i < M; i++){
    int c1, c2, d, c;
    cin >> c1 >> c2 >> d >> c;
    G[c1][c2] = G[c2][c1] = d;
    C[c1][c2] = C[c2][c1] = c;
  }
  dij(C1);
  int k = C2;
  vector<int> rel;
  while(pre[k] >= 0){
    rel.push_back(pre[k]);
    k = pre[k];
  }
  for (int i = rel.size() - 1; i >= 0; i--){
    cout << rel[i] << " ";
  }
  cout << C2 << " ";
  cout << d[C2] << " " << w[C2];
  return 0;
}