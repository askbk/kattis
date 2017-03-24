#include <iostream>

using namespace std;

int main(){
  long long a, b;
  long long n;
  while(scanf("%d" , n) != EOF) {
    cin >> a >> b;
    cout << abs(a-b) << "\n";
  }
}
