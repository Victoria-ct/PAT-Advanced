#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
  int left;
  int right;
} tree[32];
int N;
vector<int> porder(N), iorder(N);

// 子树在porder和iorder的位置
int findroot(int pbegin, int pend,int ibegin,int iend){
  if(pbegin >= N || pend < 0 || pbegin > pend || ibegin > iend){
    return 0;
  }
  int rel = porder[pend];
  // 找到其在中序的位置
  int index = 0;
  for (int i = ibegin; i <= iend; i++){
    if(iorder[i] == rel){
      index = i;
      break;
    }
  }
  if (index -1 - ibegin < 0)
    tree[rel].left = 0;
  else
    tree[rel].left = findroot(pbegin, pbegin + index - 1 - ibegin, ibegin, index - 1);
  if (iend - index - 1 < 0)
    tree[rel].right = 0;
  else
    tree[rel].right = findroot(pend - 1 - (iend - index - 1), pend - 1, index + 1, iend);
  return rel;
}
int main(){
  cin >> N;
  for (int i = 0; i < N;i++){
    int temp;
    cin >> temp;
    porder.push_back(temp);
  }
  int root = porder[N - 1],index;
  for (int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    iorder.push_back(temp);
    if (iorder[i] == root){
      index = i;
    }
  }
  tree[root].left = findroot(0, index - 1, 0, index - 1);
  tree[root].right = findroot(index, N - 2, index + 1, N - 1);
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    if(tree[temp].left != 0){
      q.push(tree[temp].left);
    }
    if(tree[temp].right != 0){
      q.push(tree[temp].right);
    }
    cout << temp;
    if(!q.empty()){
      cout << " ";
    }
  }
  return 0;
}