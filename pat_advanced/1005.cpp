#include <algorithm>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,string> number = {
  {1,"one"},
  {2,"two"},
  {3,"three"},
  {4,"four"},
  {5,"five"},
  {6,"six"},
  {7,"seven"},
  {8,"eight"},
  {9,"nine"},
  {0,"zero"},
};
int main() {
  vector<int> a;
  string N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N.length(); i++){
    sum += (N[i] - '0');
  }
  if (sum == 0) {
    a.push_back(0);
  }
  while (sum != 0) {
    a.push_back(sum % 10);
    sum /= 10;
  }
  vector<int>::reverse_iterator it;
  for (it = a.rbegin(); it != a.rend() - 1; it++){
    cout << number[*it] << " ";
  }
  cout << number[*it];
  return 0;
}
  