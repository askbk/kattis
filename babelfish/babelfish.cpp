#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  string input1, input2;
  map<string, string> dictionary;
  cin >> input1 >> input2;
  while (!input1.empty() && !input2.empty()) {
    dictionary[input2] = input1;
    cin >> input1 >> input2;
  }

  while (cin >> input1) {
    if (dictionary.count(input1)!=0) {
      cout << dictionary[input1] << "\n";
    } else {
      cout << "eh\n";
    }
  }
}
