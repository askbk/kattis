#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
  int T, N;
  cin >> T;
  for (size_t i = 0; i < T; i++) {
    cin >> N;
    int count = 0;
    priority_queue<string> prique;
    for (size_t j = 0; j < N; j++) {
      string input;
      cin >> input;
      prique.push(input);
    }
    string previous = "-1";
    for (size_t j = 0; j < N; j++) {
      string current = prique.top();
      prique.pop();
      if (current!=previous) {
        count++;
      }
      previous = current;
    }
    cout << count << "\n";
  }
}
