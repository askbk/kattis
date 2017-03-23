#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main(){
  int C, P, X, L, a, b;
  cin >> C >> P >> X >> L;

  vector< vector<int> > edge;
  edge.resize(C+1);

  bool leaving[C+1];
  bool visited[C+1];
  memset(leaving, 0, sizeof leaving);
  memset(visited, 0, sizeof visited);

  queue<int> que;

  for (size_t i = 0; i < P; i++) {
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  int temp = edge[L].size();
  for (size_t i = 0; i < temp; i++) {
    int current = edge[L][i];
    que.push(current);
  }

  leaving[L] = true;

  while (!que.empty()) {
    int current = que.front();
    que.pop();
    visited[current] = true;
    int partners = edge[current].size(), leavingPartners = 0;

    for (size_t i = 0; i < partners; i++) {
      int temp = edge[current][i];
      if (leaving[temp]) {
        ++leavingPartners;
      }

      if (!visited[temp]) {
        que.push(temp);
      }
    }

    if (leavingPartners>=(partners/2 + partners%2)) {
      leaving[current] = true;
    }

    if (current == X && leaving[current]) {
      cout << "leave";
      return 0;
    }
  }

  if (!leaving[X]) {
    cout << "stay";
  } else {
    cout << "leave";
  }
  return 0;
}
