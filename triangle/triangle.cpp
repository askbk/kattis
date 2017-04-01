#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N, TC = 1;
  while (scanf("%d", &N) != EOF) {
    long double sum = 2.5;
    for (size_t i = 1; i < N; i++) {
      sum = 1 + 1.5*sum;
    }
    sum += 3;
    int digits = 0;
    while (sum>=1) {
        sum *= 0.1;
        digits++;
    }
    cout << "Case " << TC << ": " << digits << "\n";
    ++TC;
  }
}
