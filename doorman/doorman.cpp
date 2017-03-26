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
    if (diff==X && line[0]==line[1]) {
      break;
    }
    if (count[line[0]]<count[line[1]]) {
      count[line[0]] += 1;
      line.erase(0, 1);
    } else {
      count[line[1]] += 1;
      line.erase(1, 1);
    }
    lineLength = line.length();
    diff = abs(count['W'] - count['M']);
    cout << "diff: " << diff << "\n";
  }
  cout << count['W'] + count['M'] << "\n";
}
