#include <iostream>
#include <map>
#include <string>

using namespace std;

# define MAX 100000

int main(){
  map<string, int> candidates;
  map<string, int>::iterator it;
  string input;
  for (size_t i = 0; i < MAX; i++) {
    cin >> input;
    if (input == "***") {
      break;
    }
    it = candidates.find(input);
    if (it==candidates.end()) {
      candidates.insert(input, 1)
    } else {
      candidates[input] += 1;
    }
  }
}
