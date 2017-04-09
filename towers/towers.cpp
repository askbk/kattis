#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Tower{
  double value;
  string original;
  Tower(double _value, string _original){
    value = _value;
    original = _original;
  }
};

bool wayToSort(Tower a, Tower b){
  return a.value<=b.value;
}

int main(){
  int M;
  string input;
  vector<Tower> sequence;
  vector<int> numbers;
  cin >> M;
  while (M--) {
    cin >> input;
    double value = 1;
    int length = input.size();
    int previous = 0;
    for (size_t i = 0; i < length; i++) {
      if (input[i]!='^') {
        int a = stoi(input[i]);
        numbers[previous] = numbers[previous]*10+a;
      }else{
        ++previous;
        numbers.push_back(0);
      }
    }
    int power = numbers.size();
    for (size_t i = power-1; i >= 0; --i) {
      value = pow(numbers[i], value);
    }
    cout << value << "\n";
  }
}
