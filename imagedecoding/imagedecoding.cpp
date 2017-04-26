#include <iostream>
#include <string>

using namespace std;

int main(){
  string input;
  char tegn[2] = {'.', '#'};
  bool turn = false;
  int n;

  cin >> n;
  while (n!=0) {
    while (n--) {
      getline(cin, input);
      int length = input.length();
      for (size_t i = 2; i < length; i+=2) {
        int current = (i*2)%2;
      }
    }
  }
}
