#include <iostream>

using namespace std;

int main() {
  long long a, b;
  while (scanf("%lld %lld", &a, &b) != EOF) {
    cout << abs(a - b) << "\n";
  }
}
