#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
  int N, input, length;
  bool changed;
  cin >> N;
  vector <int> cards;
  cards.resize(N);
  for (size_t i = 0; i < N; i++) {
    cin >> input;
    cards[i] = input%2;
  }
  do {
    changed = false;
    length = cards.size()-1;
    for (size_t i = 0; i < length; i++) {
      if ((cards[i]+cards[i+1])%2==0) {
        changed = true;
        cards.erase(cards.begin()+i, cards.begin()+i+2);
        break;
      }
    }
  } while(changed && length > 1);
  cout << cards.size();
}
