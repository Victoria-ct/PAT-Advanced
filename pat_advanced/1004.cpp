#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
struct node{
  int k = 0; // 子结点数量
  vector<string> CID; // 子节点ID
};
int main(){
  int N, M;
  cin >> N >> M;
  map<string, node> trees;   // RID -> node(k , CID)
  // 创建树
  for (int i = 0; i < M; i++){
    string RID;
    int K;
    node n;
    cin >> RID >> K;
    n.k = K;
    for (int j = 0; j < K; j++){
      string CID;
      cin >> CID;
      n.CID.push_back(CID);
    }
    trees[RID] = n;
  }
  //广度遍历树
  queue<string> q;
  int num = 0,result = 0;
  q.push("01"); //根结点01
  int level = 1;       //当前层级的节点数
  int nextlevel = 0;   //下一层级的节点数
  while(q.size() != 0){
    string temp = q.front();
    num += 1;
    if (trees.count(temp)){   // 该结点存在子节点
      for (int i = 0; i < trees[temp].k; i++){
        q.push(trees[temp].CID[i]);  // 将下一层的子节点放入队列
      }
      nextlevel += trees[temp].k;
    } else {
      result++;
    }
    if (level == num){
      cout << result;
      result = 0;
      num = 0;
      level = nextlevel;
      nextlevel = 0;
      if (q.size() != 1) {     
        cout << " ";
      }
    }
    q.pop();
  }
    return 0;
}
  