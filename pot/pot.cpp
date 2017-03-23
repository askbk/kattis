#include <iostream>
#include <cmath>

int main() {
  int N;
  int P;
  int rest;
  int X = 0;
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    std::cin >> P;
    rest = P % 10;
    P = (P-rest)/10;
    X += pow(P, rest);
  }
  std::cout << X << '\n';
  return 0;
}
