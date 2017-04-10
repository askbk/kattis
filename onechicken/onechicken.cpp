#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  if (N < M) {
    int diff = M - N;
    cout << "Dr. Chaz will have " << M - N;
    if (diff > 1) {
      cout << " pieces of chicken left over!\n";
    } else {
      cout << " piece of chicken left over!\n";
    }

  } else {
    int diff = N - M;
    cout << "Dr. Chaz needs " << N - M;
    if (diff > 1) {
      cout << " more pieces of chicken!\n";
    } else {
      cout << " more piece of chicken!\n";
    }
  }
}
