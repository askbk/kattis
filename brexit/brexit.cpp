#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int C, P, X, L, a, b;
  cin >> C >> P >> X >> L;

  vector<vector<int>> edge;
  edge.resize(C + 1);

  bool visited[C + 1];
  int leavingPartners[C + 1];
  memset(visited, 0, sizeof visited);
  memset(leavingPartners, 0, sizeof leavingPartners);

  queue<int> que;

  for (size_t i = 0; i < P; i++) {
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  que.push(L);

  while (!que.empty() && !visited[X]) {
    int current = que.front();
    que.pop();
    if (visited[current]) {
      continue;
    }
    visited[current] = true;

    for (size_t i = 0; i < edge[current].size(); i++) {
      int temp = edge[current][i];
      leavingPartners[temp] += 1;
      if (2 * leavingPartners[temp] >= edge[temp].size()) {
        que.push(temp);
      }
    }
  }

  if (!visited[X]) {
    cout << "stay\n";
  } else {
    cout << "leave\n";
  }
  return 0;
}
