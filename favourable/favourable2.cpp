#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T, S;
  cin >> T;
  while (T--) {
    int S, a1, a2, a3, pageNumber;
    long long favending = 0;
    string input;
    stack<int> stacc;
    vector<vector<int>> edge;
    cin >> S;
    edge.resize(401);

    while (S--) {
      cin >> pageNumber;
      cin >> input;
      if (input == "favourably") {
        edge[pageNumber].push_back(-1);
      } else if (input == "catastrophically") {
        edge[pageNumber].push_back(-2);
      } else {
        a1 = stoi(input);
        cin >> a2 >> a3;
        edge[pageNumber].push_back(a1);
        edge[pageNumber].push_back(a2);
        edge[pageNumber].push_back(a3);
      }
    }
    stacc.push(1);

    while (!stacc.empty()) {
      int current = stacc.top();

      stacc.pop();
      int neighbours = edge[current].size();
      if (neighbours == 1) {
        if (edge[current][0] == -1) {
          favending++;
        }
      } else {
        for (size_t i = 0; i < 3; i++) {
          stacc.push(edge[current][i]);
        }
      }
    }
    cout << favending << "\n";
  }
}
