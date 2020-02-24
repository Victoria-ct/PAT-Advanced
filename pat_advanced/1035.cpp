#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct account{
  string ID, pass;
  account(string _ID, string _pass):ID(_ID),pass(_pass){}
};
int main(){
  int N;
  cin >> N;
  vector<account> acc;
  for (int i = 0; i < N; i++){
    string ID, pass;
    cin >> ID >> pass;
    int flag = 0;
    for (int j = 0; j < pass.length();j++){
      if(pass[j]== '1'){
        pass[j] = '@';
        flag = 1;
      } else if(pass[j] == '0'){
        pass[j] = '%';
        flag = 1;
      } else if (pass[j] == 'l'){
        pass[j] = 'L';
        flag = 1;
      } else if (pass[j] == 'O'){
        pass[j] = 'o';
        flag = 1;
      }
    }
    if(flag){
      acc.push_back(account(ID, pass));
    }
  }
  if (acc.size()){
    cout << acc.size() << endl;
    for (int i = 0; i < acc.size();i++){
      cout << acc[i].ID << " " << acc[i].pass << endl;
    }
  } else {
    if (N == 1)
      cout << "There is " << N << " account and no account is modified";
    else
      cout << "There are " << N << " accounts and no account is modified";
  }
    return 0;
}