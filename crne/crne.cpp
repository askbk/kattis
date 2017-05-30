#include <iostream>

using namespace std;

int main(){
  long long N, vert, hor;
  cin >> N;
  vert = N/2;
  hor = N-vert;
  cout << (vert + 1)*(hor+1) << "\n";
}
