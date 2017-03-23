#include <iostream>
#include <queue>

using namespace std;

int main(){
  priority_queue<int> prique;
  int input, count = 0;
  for (size_t i = 0; i < 10; i++) {
    cin >> input;
    prique.push(input % 42);
  }
  int previous = -1;
  for (size_t i = 0; i < 10; i++) {
    int current = prique.top();
    prique.pop();
    if (current!=previous) {
      count++;
    }
    previous = current;
  }
  cout << count;
}
