#include <iostream>

int main(int argc, char const *argv[]) {
  int A, B, C, D, H, count;
  std::cin >> A >> B >> C >> D;

  for (size_t i = 0; i < 3; i++) {
    std::cin >> H;
    if (A>(H%(A+B))) {
      ++count;
    }
    if (C>(H%(C+D))) {
      ++count;
    }
    if (count==1) {
      std::cout << "one" << '\n';
    } else if (count==2) {
      std::cout << "both" << '\n';
    } else {
      std::cout << "none" << '\n';
    }
  }
  return 0;
}
