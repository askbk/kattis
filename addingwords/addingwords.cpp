#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main(){
  map<int, string> valString;
  map<string, int> stringVal;
  string input;
  while (!input) {
    cin >> input;
    if (input=="def") {
      int val;
      cin >> input >> val;
      valString[val] = input;
      stringVal[input] = val;
    } else if (input == "calc"){
      string njet;
      cin >> njet
      while (njet!='=') {
        /* code */
      }
    } else {
      memset(stringVal, 0, sizeof stringVal);
      memset(valString, 0, sizeof valString);
    }
  }
}
