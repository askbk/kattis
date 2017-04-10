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
  string map[r];      // kart
  bool visited[r][c]; // om man har besøkt
  memset(visited, 0, sizeof visited);

  for (int i = 0; i < r; i++) {
    // scanf("%s", map[i]);
    cin >> map[i];
  }

  cin >> n;

  for (size_t i = 0; i < n; i++) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    if (map[y1][x1] != map[y2][x2]) {
      cout << "neither" << endl;
      continue;
    }

    queue<pair<int, int>> que;
    bool reachable[2] = {false, false};

    int people;
    if (map[y1][x1] == '0') {
      people = 0;
    } else {
      people = 1;
    }

    que.push(make_pair(y1, x1));

    while (!que.empty()) {
      pair<int, int> current = que.front();
      que.pop();
      if (current.first == y2 && current.second == x2) {
        reachable[people] = true;
        break;
      }
      visited[current.first][current.second] = true;

      for (size_t k = 0; k < 4; k++) {
        int nxtY = current.first + dy[k];
        int nxtX = current.second + dx[k];
        if (nxtX < c && nxtX > -1 && nxtY < r && nxtY > -1 &&
            !visited[nxtY][nxtX] && map[nxtY][nxtX] == map[y1][x1]) {
          que.push(make_pair(nxtY, nxtX));
        }
      }
    }

    if (!reachable[0] &&
        !reachable[1]) { // kan man nå koordinatene for binære eller desimale?
      cout << "neither\n";
    } else if (reachable[1]) {
      cout << "decimal\n";
    } else {
      cout << "binary\n";
    }
  }
  return 0;
}
