#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
struct node{
  string name;
  int status, month, time, day, hour, minute;
};
bool cmp(node a, node b) {
  return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate) {
  double total = rate[call.hour] * call.minute + rate[24] * 60  * call.day;
  for (int i = 0; i < call.hour; i++)
      total += rate[i] * 60;
  return total / 100.0;
}
int main(){
  int rate[25] = {0};
  for (int i = 0; i < 24; i++){
    cin >> rate[i];
    rate[24] += rate[i];
  }
  int N;
  cin >> N;
  vector<node> data(N);
  for (int i = 0; i < N;i++){
    cin >> data[i].name;
    scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
    string temp;
    cin >> temp;
    data[i].status = (temp == "on-line") ? 1 : 0;
    data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
  }
  sort(data.begin(), data.end(), cmp);
  map<string, vector<node> > custom;
  for (int i = 1; i < N;i++){
    if(data[i].name == data[i - 1].name && data[i].status == 0 && data[i - 1].status == 1){
      custom[data[i].name].push_back(data[i - 1]);
      custom[data[i].name].push_back(data[i]);
    }
  }
  for (auto it : custom){
    vector<node> temp = it.second;
    cout << it.first;
    printf(" %02d\n", temp[0].month);
    double sum = 0.0;
    for (int i = 0; i < temp.size(); i+=2){
      double price = billFromZero(temp[i + 1], rate) - billFromZero(temp[i], rate);
      sum += price;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", temp[i].day, temp[i].hour, temp[i].minute, temp[i + 1].day, temp[i + 1].hour, temp[i + 1].minute, temp[i+1].time - temp[i].time, price);
    }
    printf("Total amount: $%.2lf\n", sum);
  }
  return 0;
}

  