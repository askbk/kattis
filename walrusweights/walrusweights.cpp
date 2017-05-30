#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int DP[2000];

void rec(int v){

}

int main(){
  int n, vekt;
  memset(DP, -1, sizeof DP);
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> vekt;
    DP[vekt] = vekt;
  }
  int previous = 0;
  for (size_t i = 0; i < 2000; i++) {
    if (DP[i]!=-1) {
      int a = DP[i] + previous;
      if (a<2000) {
        DP[a] = a;
      }
      previous = DP[i];
    }
  }
  int curr = 0;
  for (size_t i = 0; i < 2000; i++) {
    if (abs(1000-curr)>abs(1000-DP[i])) {
      curr = DP[i];
    } else if (abs(1000-curr)==abs(1000-DP[i])) {
      curr = max(curr, DP[i]);
    }
  }
  cout << curr << "\n";
}
