#include <iostream>
#include <string>

using namespace std;

int main(){
  int T;

  cin >> T;
  for (size_t i = 0; i < T+1; i++) {
    string input;
    getline(cin, input);
    if (input.substr(0,10) == "simon says") {
      cout << input.substr(11, 1000) << "\n";
    } else {
      cout << "\n";
      continue;
    }
  }
  return 0;
}
