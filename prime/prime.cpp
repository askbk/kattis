#include <iostream>
#include <vector>

int main() {
  int N;
  cin >> N;
  vector<int> primes;
  vector<int>::iterator it = primes.begin();

  for (size_t i = 2; i < N; i++) {
    primes.push_back(i);
  }

  while (it != primes.end()) {
    for (vector<int>::iterator et = it + 1; et != primes.end(); ++et) {
      if ((*et) % (*it) == 0) {
        primes.erase(et);
      }
    }
    ++it;
  }
  return 0;
}
