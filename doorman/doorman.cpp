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
  while(lineLength>0){
    if (count[line[0]]<count[line[1]]) {
      count[line[0]] += 1;
      line.erase(0, 1);
    } else {
      if (line[0]==line[1] && diff == X && line[0]==max(count['W'], count['M'])) {
        break;
      }
      count[line[1]] += 1;
      line.erase(1, 1);
    }
    lineLength = line.length();
    diff = abs(count['W'] - count['M']);
    if (diff>X) {
      cout << count['W'] + count['M'] - 1 << "\n";
      return 0;
    }
  }
  cout << count['W'] + count['M'] << "\n";
}
