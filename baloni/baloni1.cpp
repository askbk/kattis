#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(){
  priority_queue<int> lowest;
  int N, H, arrows = 0;
  cin >> N;
  int balloonsLeft = N;
  int balloon[N];
  bool shot[N];
  memset(shot, 0, sizeof shot);
  for (size_t i = 0; i < N; i++) {
    cin >> balloon[i];
    lowest.push(-balloon[i]);
  }
  int arrowHeight, firstNotShot = 0, iterator = 0;
  while (balloonsLeft) {
    ++arrows;
    arrowHeight = balloon[firstNotShot];
    iterator = firstNotShot;
    cout << "first not shot: " << firstNotShot << "\n";
    firstNotShot = -1;
    int low = lowest.top();
    lowest.pop();
    cout << "arrowHeight: " << arrowHeight << "\n";
    for (size_t i = 0; i < N && arrowHeight>=low; i++) {
      if (!shot[i] && arrowHeight==balloon[i]) {
        arrowHeight--;
        cout << "arrowHeight: " << arrowHeight << "\n";
        shot[i] = true;
        balloonsLeft--;
        if (balloon[i]==-low) {
          low = lowest.top();
          lowest.pop();
        }
      } else if (firstNotShot == -1){
        firstNotShot = i;
      }
    }
  }
  cout << arrows;
}
