#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;

int N;
vector<int> tree;
vector<int> trail;
int Hmin = 1, Hmax = 1;
void DFS(int node){
  if (node * 2 > N && node * 2 + 1 > N ){
    if (node <= N)
      for (int i = 0; i < trail.size(); i++)
        printf("%d%s", trail[i], i != trail.size() - 1 ? " " : "\n");
    
  } else {
    trail.push_back(tree[node * 2 + 1]);
    DFS(node * 2 + 1);
    trail.pop_back();
    trail.push_back(tree[node * 2]);
    DFS(node * 2);
    trail.pop_back();
  }
}

int main(){
  cin >> N;
  tree.push_back(0);
  for (int i = 1; i <= N; i++){
    int data;
    cin >> data;
    tree.push_back(data);
  }
  trail.push_back(tree[1]);
  DFS(1);

  for (int i = 2; i <= N; i++){
    if (tree[i / 2] > tree[i]){
      Hmin = 0;
    } else if (tree[i / 2] < tree[i]){
      Hmax = 0;
    }
  }
  if (Hmin){
    printf("Min Heap");
  } else if (Hmax) {
    printf("Max Heap");
  } else {
    printf("Not Heap");
  }
  return 0;
}