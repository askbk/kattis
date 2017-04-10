#include <iostream>

using namespace std;

int main() {
  int N, t, total = 0;
  cin >> N;
  while (N--) {
    cin >> t;
    if (t < 0) {
      ++total;
    }
  }
  cout << total;
}
