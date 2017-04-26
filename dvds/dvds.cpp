#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int k, n;
  vector<int> unordered;
  map<vector<int>, bool> visited;
  cin >> k;
  while (k--) {
    queue<vector<int>> que[2];
    cin >> n;
    unordered.resize(n);
    for (size_t i = 0; i < n; i++) {
      cin >> unordered[i];
    }
    que[0].push(unordered);
    sort(unordered.begin(), unordered.end());
    que[1].push(unordered);
    int moves = 0;
    bool solved = false;
    vector<vector<int>> changed;
    changed.resize(2);
    while (!solved) {
      for (size_t i = 0; i < 2; i++) {
        que.pop();
        if (includes(changed[0].begin(), changed[0].end(), changed[1].begin(),
                     changed[1].end())) {
          solved = true;
          break;
        }

        moves++;
      }
    }
  }
}
