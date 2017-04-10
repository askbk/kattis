#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edge;
int super[1001];
double flow[1001];
double required[1001];

double DFS(int node) {
  if (required[node] != -1) {
    return required[node];
  }
  int children = edge[node].size();
  double ans = 0;
  for (size_t i = 0; i < children; i++) {
    int current = edge[node][i];
    ans = max(ans, DFS(current) / flow[current]);
  }
  if (super[node] == 1) {
    return sqrt(ans);
  } else {
    return ans;
  }
}

int main() {
  int N, A, B, T;
  double X, K;
  cin >> N;
  N;
  edge.resize(N + 1);
  for (size_t i = 1; i < N; i++) {
    cin >> A >> B >> X >> T;
    X *= 0.01;
    super[B] = T;
    flow[B] = X;
    edge[A].push_back(B);
  }

  for (size_t i = 1; i <= N; i++) {
    cin >> K;
    if (K != -1 && super[i] == 1) {
      required[i] = sqrt(K);
    } else {
      required[i] = K;
    }
  }
  printf("%.3f\n", DFS(1));
  return 0;
}
