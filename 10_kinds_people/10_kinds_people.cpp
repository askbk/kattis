#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int r, c, n;
  int dx[] = {-1, 0, 1, 0}; // bevegelser
  int dy[] = {0, -1, 0, 1};
  cin >> r >> c;
  string map[r], input;  // kart
  bool visited[r][c][2];
  for (int i = 0; i < r; i++) {
    cin >> map[i];
  }

  cin >> n;
  while (n--) {
    memset(visited, 0, sizeof visited);
    int y1, x1, y2, x2;

    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;

    if (map[y1][x1] != map[y2][x2]) {
      cout << "neither\n" << endl;
      continue;
    }

    queue<pair<int, int>> que[2];
    bool reachable[2] = {false, false};

    int people;
    char cPeople = map[y1][x1];

    if (cPeople == '0') {
      people = 0;
    } else {
      people = 1;
    }

    que[0].push(make_pair(y1, x1));
    que[1].push(make_pair(y2, x2));

    while (!que[0].empty() && !que[1].empty()) {
      for (size_t i = 0; i < 2; i++) {
        pair<int, int> current = que[i].front();
        que[i].pop();
        if (visited[current.first][current.second][(i + 1) % 2]) {
          reachable[people] = true;
          break;
        }

        for (size_t k = 0; k < 4; k++) {
          int nxtY = current.first + dy[k];
          int nxtX = current.second + dx[k];
          if (nxtX < c && nxtX > -1 && nxtY < r && nxtY > -1 &&
              !visited[nxtY][nxtX][i] && map[nxtY][nxtX] == cPeople) {
            que[i].push(make_pair(nxtY, nxtX));
            visited[nxtY][nxtX][i] = true;
          }
        }
      }
      if (reachable[people]) {
        break;
      }
    }

    if (!reachable[0] && !reachable[1]) {
      cout << "neither\n";
    } else if (reachable[1]) {
      cout << "decimal\n";
    } else {
      cout << "binary\n";
    }
  }
  return 0;
}
