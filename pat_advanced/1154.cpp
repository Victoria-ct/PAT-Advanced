#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
bool vis[10000] = {false};
vector<int> G[10000];
int v[10000];
set<int> color;


int main(){
  int N, M, K;
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> K;
  for (int i = 0; i < K; i++){
    int flag = 0;
    color.clear();
    for (int j = 0; j < N; j++){
      cin >> v[j];
      color.insert(v[j]);
    }
    for (int j = 0; j < N; j++){
      for (int z = 0; z < G[j].size(); z++){
        if (v[G[j][z]] == v[j]){
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
    }
    if (flag)
      printf("No\n");
    else
      printf("%d-coloring\n", color.size());
  }

    return 0;
}