#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main(){
  int M, N, K;
  cin >> M >> N >> K;
  
  for (int i = 0; i < K; i++){
    int status[1001] = {0}; //0:未入栈或出栈  1:入栈  2:出栈
    int flag = 0; 
    for (int j = 0; j < N; j++){
      int temp;
      cin >> temp;
      status[temp] = 2;
      // 比temp大的数字不能在栈内
      for (int z = temp + 1; z < N;z++){
        if (status[z] == 1){
          flag = 1;
          break;
        }
      }
      // 比temp小的数字在栈内总数不能超过M
      int num = 1;
      for (int z = 1; z < temp; z++){
        if(status[z] == 0){
          status[z] = 1;  //比temp小的要么再栈内要么已经出栈
        }
        if(status[z] == 1){
          num++;
        }
        if (num > M){
          flag = 1;
          break;
        }
      }
    }
    if (flag){
      cout << "NO" << endl;
    }
    if(!flag){
      cout << "YES" << endl;
    }
  }
    return 0;
}