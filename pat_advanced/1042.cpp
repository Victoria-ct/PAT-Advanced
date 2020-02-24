#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct card{
  int lo, id;
};
int cmp(card a,card b){
  return a.lo < b.lo ? 1 : 0;
}
int main(){
  int K;
  cin >> K;
  card cards[55];
  int temps[55];
  for (int i = 1; i <= 54;i++){
    cin >> cards[i].lo;
    cards[i].id = i;
    temps[i] = cards[i].lo;
  }
  for (int i = 1; i < K;i++){
    for (int j = 1; j <= 54;j++){
      cards[j].lo = temps[cards[j].lo];
    }
  }
  sort(cards, cards+55, cmp);
  for (int i = 1; i <= 54; i++){
    if(cards[i].id <= 13)
      cout << "S" << cards[i].id;
    else if (cards[i].id <= 26)
      cout << "H" << cards[i].id - 13;
    else if (cards[i].id <= 39)
      cout << "C" << cards[i].id - 26;
    else if (cards[i].id <= 52)
      cout << "D" << cards[i].id - 39;
    else 
      cout << "J" << cards[i].id - 52;
    if (i != 54)
      cout << " ";
  }
    return 0;
}