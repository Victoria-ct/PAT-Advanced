#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxV = 10001;
vector<int> Adj[maxV];
bool vis[maxV] = {false};
int rel[maxV] = {0};
int N;
int r = 1, maxroot = 1;
void DFS(int root, int num, int begin){
  vis[root] = true;
  int i;
  for (i = 0; i < Adj[root].size(); i++){
    if(vis[Adj[root][i]] == false){
      DFS(Adj[root][i], num+1, begin);
    }
  }
  if (i == Adj[root].size() && num > rel[begin]){
    rel[begin] = num;
  }
}
void DFStraver(){
  DFS(1, 1, 1);
  for (int i = 2; i <= N;i++){
    if(vis[i] == false){
      r++;
      DFS(i, 1, i);
    }
  }
  if (r == 1){
    for (int i = 2; i <= N;i++){
      fill(vis, vis + N + 1, false);
      DFS(i, 1, i);
      if (rel[maxroot] < rel[i]){
        maxroot = i;
      }
    }
  }
}
int main(){
  cin >> N;
  for (int i = 0; i < N - 1; i++){
    int a, b;
    cin >> a >> b;
    Adj[a].push_back(b);
    Adj[b].push_back(a);
  }
  DFStraver();
  if(r == 1){
    for (int i = 1; i <= N; i++){
      if(rel[maxroot] == rel[i]){
        cout << i << endl;
      }
    }
  } else{
    cout << "Error: " << r << " components";
  }
  return 0;
}