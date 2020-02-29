#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
  int level;
  vector<int> cid;
};
int main(){
  int N, M;
  cin >> N >> M;
  vector<node> tree(N + 1);
  for (int i = 0; i < M; i++){
    int id, k, cid;
    cin >> id >> k;
    for (int j = 0; j < k; j++){
      cin >> cid;
      tree[id].cid.push_back(cid);
    }
  }
    queue<int> q;
    q.push(1);
    tree[1].level = 1;
    int max = 1;  // 最大一代的节点数
    int maxlevel = 1; 
    int num = 0;  // 当前层的节点数
    int currentlevel = 1;
    while(!q.empty()){
      int id = q.front();
      if (tree[id].level > currentlevel){
        currentlevel++;
        num = 0;
      }
      num++;
      if (max < num){
        max = num;
        maxlevel = currentlevel;
      }
      q.pop();
      for (int i = 0; i < tree[id].cid.size();i++){
        int cid = tree[id].cid[i];
        q.push(cid);
        tree[cid].level = tree[id].level + 1;
      }
    }
    cout << max << " " << maxlevel; 
    return 0;
}

  