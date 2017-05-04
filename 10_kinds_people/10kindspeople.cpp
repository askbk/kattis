#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class UnionFind {
private:
  vector<vector<ii>> p;
  vector<vector<int>> setSize, rank;
  int numSets;

public:
  UnionFind(int r, int c) {
    p.resize(r);
    setSize.resize(r);
    rank.resize(r);
    for (size_t i = 0; i < r; i++) {
      p[i].resize(c);
      setSize[i].resize(c);
      rank[i].resize(c);
      for (size_t j = 0; j < c; j++) {
        p[i][j] = make_pair(i, j);
        setSize[i][j] = 1;
        rank[i][j] = 0;
      }
    }
  }
  ii findSet(ii i) {
    cout << "leader of " << i.first << " " << i.second << " is"
         << p[i.first][i.second].first << " " << p[i.first][i.second].second
         << "\n";
    return (p[i.first][i.second] == make_pair(i.first, i.second))
               ? i
               : (p[i.first][i.second] = findSet(p[i.first][i.second]));
  }
  bool inSameSet(ii i, ii j) { return findSet(i) == findSet(j); }
  void unionSet(ii i, ii j) {
    if (!inSameSet(i, j)) {
      ii x = findSet(i), y = findSet(j);
      if (rank[x.first][x.second] > rank[y.first][y.second]) {
        p[y.first][y.second] = x;
        setSize[x.first][x.second] += setSize[y.first][y.second];
      } else {
        p[x.first][x.second] = y;
        setSize[y.first][y.second] += setSize[x.first][x.second];
        if (rank[x.first][x.second] == rank[y.first][y.second]) {
          rank[x.first][x.second]++;
        }
      }
    }
  }
  int sizeOfSet(ii i) {
    ii temp = findSet(i);
    return setSize[temp.first][temp.second];
  }
};

int main() {
  int r, c, n, y1, x1, y2, x2;
  cin >> r >> c >> n;
  char map[r][c], input; // kart
  UnionFind UF(r, c);
  for (int i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      cin >> map[i][j];
      if (i != 0) {
        if (map[i - 1][j] == map[i][j]) {
          UF.unionSet(make_pair(i - 1, j), make_pair(i, j));
        }
      }
      if (j != 0) {
        if (map[i - 1][j] == map[i][j]) {
          UF.unionSet(make_pair(i - 1, j), make_pair(i, j));
        }
      }
    }
  }
  return 0;
  while (n--) {
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    if (UF.inSameSet(make_pair(y1, x1), make_pair(y2, x2))) {
      cout << "seg4\n";
      if (map[y1][x1] == '0') {
        cout << "binary\n";
      } else {
        cout << "decimal\n";
      }
    } else {
      cout << "neither\n";
    }
  }
}
