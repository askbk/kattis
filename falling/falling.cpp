#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int D, upper, lower, cursor, value;
  cin >> D;
  for (size_t i = 1; i < 100001; i++) {
    lower = 0, upper = i, lg = log2(i);
    while (lower <= upper) {
      cursor = (upper + lower) / 2;
      value = i * i - cursor * cursor;
      if (value == D) {
        cout << cursor << " " << i << "\n";
        return 0;
      } else if (value < D) {
        upper = cursor - 1;
      } else if (value > D) {
        lower = cursor + 1;
      }
    }
  }
  cout << "impossible"
       << "\n";
}
