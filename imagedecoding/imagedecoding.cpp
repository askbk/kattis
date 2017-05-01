#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  char current;
  int n = 0, places;
  bool first = true;

  cin >> n;
  while (n != 0) {
    int prevLength = 0;
    bool error = false;
    n++;
    while (n != 0) {
      int curLength = 0;
      getline(cin, input);
      int strLength = input.length(), number;

      current = input[0];
      for (size_t i = 2; i < strLength; i++) {
        if (input[i] == ' ') {
          continue;
        }
        places = 0;
        for (size_t j = 0; j < 3; j++) {
          if (input[i + j] == ' ') {
            break;
          }
          ++places;
        }
        number = stoi(input.substr(i, places));

        i += places - 1;
        for (size_t j = 0; j < number; j++) {
          cout << current;
          curLength++;
        }
        if (current == '.') {
          current = '#';
        } else {
          current = '.';
        }
      }
      if (prevLength == 0) {
        prevLength = curLength;
      } else if (prevLength != curLength) {
        error = true;
      }
      if (first) {
        first = false;
      } else {
        cout << "\n";
      }
      n--;
    }
    if (error) {
      cout << "Error decoding image\n";
    }
    cin >> n;
  }
}
