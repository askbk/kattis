#include <iostream>

using namespace std;

int main(){
  int T, N, temp;
  cin >> T;
  while (T--) {
    cin >> N;
    temp = N/400;
    if (400*temp<N) {
      cout << temp + 1 << "\n";
    } else {
      cout << temp << "\n";
    }

  }
}
