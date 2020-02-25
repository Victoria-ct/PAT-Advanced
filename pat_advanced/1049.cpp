#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int sum = 0;
  int i = 1;   // 当前数字位的位数  1、10、100....
  int n = N;
  while(N != 0){
    int temp = N % 10;  // 当前数字位
    if (temp == 0){    
      sum += (N / 10) * i;       // 当前位为0，出现1的次数为左数*当前位数i
    } else if(temp == 1){      
      sum += (N / 10) * i + (n % i) + 1;   // 当前位为1，出现1的次数为左数*当前位数i + 右数 + 1
    } else {   
      sum += (N / 10 + 1) * i;    // 当前位大于1，出现1的次数为（左数+1）*当前位数i
    }
    i *= 10;
    N /= 10;
  }
  cout << sum;        //出现1的总次数 = 每个位出现1的次数的累加
}
  