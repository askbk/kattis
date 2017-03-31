#include <iostream>

using namespace std;

int main(){
  int pieces[] = {1, 1, 2, 2, 2, 8};
  int input[8];
  for (size_t i = 0; i < 6; i++) {
    cin >> input[i];
    cout << pieces[i] - input[i] << " ";
  }
}
