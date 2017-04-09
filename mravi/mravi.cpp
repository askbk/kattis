#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



struct PipeTo{
  PipeTo();
  PipeTo(const double _flow, const int _super):
    super(_super), flow(_flow) {}
  int super;
  double flow;
};

vector< vector<int> > edge;
vector<PipeTo> pipe;
vector<double> required;

double DFS(int node){
  if (required[node]!=-1) {
    return required[node];
  }
  int children = edge[node].size();
  vector< pair <double, double> > flowPair;
  for (size_t i = 0; i < children; i++) {
    int current = edge[node][current];
    flowPair.push_back(make_pair(DFS(current), pipe[current].flow));
  }
  sort(flowPair.begin(), flowPair.end(), [](auto &left, auto &right) {
    return left.second*left.first > right.first*right.second;
});
  return flowPair[0].first/flowPair[0].second;
}

int main(){
  int N, A, B, T, n;
  double X, K;
  cin >> N;
  edge.resize(N);
  pipe.reserve(N);
  required.resize(N);
  for (size_t i = 0; i < N; i++) {
    cin >> A >> B >> X >> T;
    X *= 0.01;
    pipe[B-1] = PipeTo(X, T);
    edge[A-1].push_back(B-1);
  }

  for (size_t i = 0; i < N; i++) {
    cin >> K;
    if (pipe[i].super==1) {
      required[i] = sqrt(K);
    } else {
      required[i] = K;
    }
  }

  cout << DFS(0) << "\n";
  return 0;
}
