#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N;
  while (scanf("%d", &N) != EOF) {
    int max = sqrt(N), sum = 1;
    for (size_t i = 2; i <= max; i++) {
      if (N%i==0) {
        int partial = N/i;
        if (i!=partial) {
          sum += i + N/i;
        } else {
          sum += i;
        }
      }
    }
    if (sum==N) {
      cout << N << " perfect\n";
    } else if (abs(sum-N)<=2){
      cout << N << " almost perfect\n";
    } else {
      cout << N << " not perfect\n";
    }
  }
}
