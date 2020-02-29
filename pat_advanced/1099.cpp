#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct node {
  int id,left, right;
  int w;
};

int main(){
  int N;
  cin >> N;
  vector<node> tree(N);
  vector<int> weight(N);
  vector<int> vis(N);
  stack<node> s;
  for (int i = 0; i < N; i++) {
    cin >> tree[i].left >> tree[i].right;
    tree[i].id = i;
  }
  for (int i = 0; i < N; i++) {
    cin >> weight[i];
  }
  sort(weight.begin(), weight.end());
  int j = 0;
  s.push(tree[0]);
  while(s.size() != 0){
    node data = s.top();
    if(data.left != -1 && vis[data.left] != 1){
      s.push(tree[data.left]);
      vis[data.left] = 1;
    } else {
      tree[data.id].w = weight[j];
      j++;
      s.pop();
      if(data.right != -1 && vis[data.right] != 1){
        s.push(tree[data.right]);
        vis[data.right] = 1;
      }
    }
  }
  queue<node> q;
  q.push(tree[0]);
  while(q.size()!=0){
    node data = q.front();
    q.pop();
    printf("%d", data.w);
    if (data.left != -1)
      q.push(tree[data.left]);
    if (data.right != -1)
      q.push(tree[data.right]);
    if(!q.empty())
      printf(" ");
  }
  return 0;
}