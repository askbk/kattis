#include <iostream>

using namespace std;

int main() {
  int T, N;
  unsigned long long sum = 0, temp = 0;
  cin >> T;
  for (size_t i = 0; i < T; i++) {
    cin >> N;
    sum = 0;
    for (size_t j = 0; j < N; j++) {
      cin >> temp;
      sum += temp % N;
      sum %= N;
    }
    if (sum % N == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
