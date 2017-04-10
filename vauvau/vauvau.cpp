#include <iostream>

using namespace std;

int main() {
  int A, B, C, D, H, count;
  cin >> A >> B >> C >> D;

  for (size_t i = 0; i < 3; i++) {
    cin >> H;
    H--;
    if (A > (H % (A + B))) {
      ++count;
    }
    if (C > (H % (C + D))) {
      ++count;
    }
    if (count == 1) {
      cout << "one" << '\n';
    } else if (count == 2) {
      cout << "both" << '\n';
    } else {
      cout << "none" << '\n';
    }
    count = 0;
  }
  return 0;
}
