#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
struct timec{
  int ah, am, as;
  int dt;
  timec(int _ah,int _am,int _as,int _dt):ah(_ah),am(_am),as(_as),dt(_dt){}
};
int compareTime(timec a,timec b){
  return (a.ah * 3600 + a.am * 60 + a.as) > (b.ah * 3600 + b.am * 60 + b.as);
}
// 时间差
int computeTime(timec a,timec b){
  return (b.ah * 3600 + b.am * 60 + b.as) - (a.ah * 3600 + a.am * 60 + a.as);
}
int main(){
  int N, K;
  cin >> N >> K;
  vector<timec> tb;
  vector<timec> wb; //窗口空闲时间
  timec bt(8,0,0,0);
  timec et(17,0,0,0);
  for (int i = 0; i < N;i++){
    int ah, am, as, dt;
    scanf("%d:%d:%d %d", &ah, &am, &as, &dt);
    timec at(ah, am, as, dt);
    if(compareTime(et,at)){
      tb.push_back(at);
    }
  }
  //初始化窗口
  for (int i = 0; i < K;i++){
    wb.push_back(bt);
  }
  // 排序
  sort(tb.begin(), tb.end(), compareTime);
  double sum = 0;
  int ser = 0; // 服务人数
  for (int i = tb.size() - 1; i >= 0; i--){
      // 找到时间最近的窗口
    int min = 0;
    for (int j = 0; j < wb.size(); j++){
      int temp = computeTime(wb[min], wb[j]);
      if(temp < 0){
        min = j;
      }
    }
    // 客户到达时间早于窗口空闲时间,需要等待
    ser++;
    if (computeTime(tb[i], wb[min]) > 0){
      sum += computeTime(tb[i], wb[min]);
      wb[min].am += tb[i].dt;
    } else{
      wb[min].am = tb[i].am + tb[i].dt;
      wb[min].ah = tb[i].ah;
      wb[min].as = tb[i].as;
    }
  }
  if (ser == 0){
    printf("%.1f", sum);
  } else{
    printf("%.1lf", sum / ser / 60);
  }
  return 0;
}