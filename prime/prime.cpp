#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> primes;
  std::vector<int>::iterator it = primes.begin();

  for (size_t i = 2; i < N; i++) {
    primes.push_back(i);
  }

  while (it!=primes.end()) {
    for (std::vector<int>::iterator et = it+1; et!=primes.end(); ++et) {
      if ((*et)%(*it)==0) {
        primes.erase(et);
      }
    }
    ++it;
  }
  return 0;
}
