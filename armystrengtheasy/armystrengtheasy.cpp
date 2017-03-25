#include <iostream>
#include <queue>

using namespace std;

int main(){
  int T, G, M;
  cin >> T;

  while (T--) {
    priority_queue<int> army[2]; //0 = godzilla, 1 = mecha
    cin >> G >> M;
    while (G--) {
      int input;
      cin >> input;
      input = -input;
      army[0].push(input);
    }
    while (M--) {
      int input;
      cin >> input;
      input = -input;
      army[1].push(input);
    }
    while (!army[0].empty() && !army[1].empty()) {
      int gArmy = army[0].top();
      int mArmy = army[1].top();
      if (gArmy==mArmy) {
        army[1].pop();
      } else if (gArmy > mArmy) { //gArmy er svakere
        army[0].pop();
      } else {
        army[1].pop();
      }
    }
    if (army[0].empty() && army[1].empty()) {
      cout << "uncertain\n";
    } else if (army[0].empty()){
      cout << "MechaGodzilla\n";
    } else {
      cout << "Godzilla";
    }
  }
  return 0;
}
