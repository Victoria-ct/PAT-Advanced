#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node {
  int index;
  node *left, *right;
};
node* newnode(int v){
  node* n = new node;
  n->index = v;
  n->left = n->right = NULL;
  return n;
}
void insert(node* root,int v){
  node *n = root;
  while(n != NULL){
    if (v < n -> index)
      if (n -> left != NULL)
        n = n->left;
      else{
        n->left = newnode(v);
        break;
      }
    else
      if (n -> right != NULL)
        n = n->right;
      else{
        n->right = newnode(v);
        break;
      }
  }
}
void minsert(node* mroot,int v){
  node *n = mroot;
  while(n != NULL){
    if (v < n -> index)
      if (n -> right != NULL)
        n = n->right;
      else{
        n->right = newnode(v);
        break;
      }
    else
      if (n -> left != NULL)
        n = n->left;
      else{
        n->left = newnode(v);
        break;
      }
  }
}
int is_preorder(vector<int> order, node *root){
  int i = 0;
  stack<node*> st;
  st.push(root);
  while(!st.empty()){
    node* data = st.top();
    st.pop();
    if (order[i] == data->index){
     i++;
     if (data->right)
      st.push(data->right);
     if (data->left)
      st.push(data->left);
    } else{
      break;
    }
  }
  if (i < order.size() - 1)
    return 0;
  return 1;
}

void postorder(node *root){
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->index);
}

int main(){
  int N;
  scanf("%d", &N);
  vector<int> order;
  node *root, *mroot;
  for (int i = 0; i < N; i++){
    int key;
    scanf("%d", &key);
    order.push_back(key);
    if (i == 0){
      root = newnode(key);
      mroot = newnode(key);
    } else {
      insert(root, key);
      minsert(mroot, key);
    }
  }
  if(is_preorder(order, root)){
    printf("YES\n");
    postorder(root -> left);
    postorder(root -> right);
    printf("%d",root->index);
    } else if (is_preorder(order,mroot)){
    printf("YES\n");
    postorder(mroot -> left);
    postorder(mroot -> right);
    printf("%d",mroot->index);
  } else {
    printf("NO");
  }

  return 0;
}

  