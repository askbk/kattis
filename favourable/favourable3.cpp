#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

long long paths[401][401];
vector< vector <int> > node;

long long DFS(int u, int t){
  if (u == t) {
    return 1;
  }
  if (paths[u][t]!=-1) {
    return paths[u][t];
  }
  int temp = node[u].size();
  if (temp==0) {
    paths[u][t] = 0;
    return 0;
  }
  long long nPaths = 0;
  for (size_t i = 0; i < temp; i++) {
    nPaths += DFS(node[u][i], t);
  }
  paths[u][t] = nPaths;
  return nPaths;
}

int main(){
  int T, S;
  cin >> T;
  while (T--) {
    int S, pageNumber;
    int a[3];
    long long favending = 0;
    vector<int> endings;
    node.resize(401);
    memset(paths, -1, sizeof paths);
    node.clear();
    string input;
    cin >> S;

    while (S--) {
      cin >> pageNumber;
      cin >> input;
      if (input == "favourably") {
        endings.push_back(pageNumber);
      } else if (input != "catastrophically") {
        a[0] = stoi(input);
        cin >> a[1] >> a[2];
        for (size_t i = 0; i < 3; i++) {
          node[pageNumber].push_back(a[i]);
        }
      }
    }

    int temp = endings.size();
    for (size_t i = 0; i < temp; i++) {
      favending += DFS(1, endings[i]);
    }
    cout << favending << "\n";
  }
}
