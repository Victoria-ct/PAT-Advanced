#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
struct stu{
  string name;
  string ID;
  int grade;
};
int main(){
  int N;
  cin >> N;
  stu mrel, frel;
  mrel.grade = 101;
  frel.grade = -1;
  for (int i = 0; i < N;i++){
    string name, ID;
    char gender;
    int grade;
    cin >> name >> gender >> ID >> grade;
    if(gender == 'M' && grade < mrel.grade){
      mrel.name = name;
      mrel.ID = ID;
      mrel.grade = grade;
    } else if(gender == 'F' && grade > frel.grade){
      frel.name = name;
      frel.ID = ID;
      frel.grade = grade;
    }
  }
  if(frel.grade == -1){
    cout << "Absent" << endl;
  } else{
    cout << frel.name << " "<< frel.ID <<endl;
  }
  if(mrel.grade == 101){
    cout << "Absent" << endl;
  } else{
    cout << mrel.name << " "<< mrel.ID <<endl;
  }
  if(frel.grade == -1 || mrel.grade == 101){
    cout << "NA";
  } else{
    cout << frel.grade - mrel.grade;
  }
  return 0;
}