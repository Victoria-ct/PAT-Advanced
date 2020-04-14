#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string s1, s2, s3, s4;  
  string day[7] = {"MON", "TUE", "WED","THU","FRI","SAT","SUN"};
  cin >> s1 >> s2 >> s3 >> s4;
  int flag = 0;
  for (int i = 0; i < s1.length() && i < s2.length(); i++){
    if (s1[i] == s2[i]){
      if (flag == 0 && s1[i] >= 'A' && s1[i] <= 'G'){
        cout << day[s1[i] - 'A'] << " ";
        flag++;
      } else if (flag == 1){
        if (s1[i] >= 'A' && s1[i] <= 'N'){
          printf("%02d:", s1[i] - 'A' + 10);
        } else if(s1[i] >= '0' && s1[i] <= '9') 
          printf("%02d:",s1[i] - '0');
          else
            continue;
          break;
      }
    }
  }
  for (int i = 0; i < s3.length() && i < s4.length(); i++){
    if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))){
      printf("%02d",i);
      break;
    }
  }
  return 0;
}
