#include <iostream>

using namespace std;

int main() {
  int H, M, hour, min;
  cin >> H >> M;
  hour = (H + 23) % 24;
  min = (M + 15);
  if (min > 60) {
    ++hour;
    hour %= 24;
    min %= 60;
  }
  cout << hour << " " << min;
}
