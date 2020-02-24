#include <algorithm>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct record{
  string ID;
  int ih;
  int im;
  int is;
  int oh;
  int om;
  int os;
};
int compareTimeIn(record a, record b){
  if (a.ih > b.ih) {
    return 1;
  } else if (a.ih == b.ih && a.im > b.im) {
    return 1;
  } else if (a.im == b.im && a.is > b.is) {
    return 1;
  } 
  return 0;
}
int compareTimeOut(record a, record b){
  if (a.oh > b.oh) {
    return 1;
  } else if (a.oh == b.oh && a.om > b.om) {
    return 1;
  } else if (a.om == b.om && a.os > b.os) {
    return 1;
  } 
  return 0;
}
int main(){
  int M;
  cin >> M;
  vector<record> re(M);
  int max = 0, min = 0;
  for (int i = 0; i < M; i++){
    cin >> re[i].ID;
    scanf(" %d:%d:%d %d:%d:%d", &re[i].ih, &re[i].im, &re[i].is, &re[i].oh, &re[i].om, &re[i].os);
    if (compareTimeOut(re[i],re[max])) {
      max = i;
    }
    if (compareTimeIn(re[min],re[i])) {
      min = i;
    }
  }
  printf("%s %s", re[min].ID.c_str(), re[max].ID.c_str());
  return 0;
}
  