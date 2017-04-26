#include <iostream>

using namespace std;

long long nCr(long long n, long long r){
  if (r > n/2) {
    r = n-r;
  }
  long long ans = 1;
  for (size_t i = n; i > n - r; --i) {
    ans *= i;
    ans /= n-i+1;
  }
  return ans;
}

int main(){
  long long N, relations = 0;
  cin >> N;
  for (size_t i = N; i > 1; --i) {
    relations += nCr(N, i);
  }
  cout << relations << "\n";
  return 0;
}
