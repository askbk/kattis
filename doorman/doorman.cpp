#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  int X;
  map<char, int> count;
  count['W'] = 0;
  count['M'] = 0;
  string line;
  cin >> X >> line;
  int lineLength = line.length();
  int diff = 0;
  while(diff <= X && lineLength>0){
    diff = abs(count['W'] - count['M']);
    if (diff <= X) {
      if (count[line[0]]<count[line[1]]) {
        count[line[0]] += 1;
        line.erase(0, 1);
      } else {
        count[line[1]] += 1;
        line.erase(1, 1);
      }
    } else {
      break;
    }
    lineLength = line.length();
  }
  cout << count['W'] + count['M'] << "\n";
}
