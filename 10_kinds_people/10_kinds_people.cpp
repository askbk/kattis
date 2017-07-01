#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, n;
    int dx[] = {-1, 0, 1, 0}; // bevegelser
    int dy[] = {0, -1, 0, 1};
    cin >> r >> c;
    string map[r], input;  // kart
    int areas[r][c]; // hvilke områder som kan nå hverandre
    bool visited[r][c];
    int area = 3;

    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }

    for(int l = 0; l < r; ++l){
        for(int m = 0; m < c; ++m){
            if(!visited[l][m]){
                queue<pair<int, int>> que;
                
                que.push(make_pair(l, m));
                
                while (!que.empty()) {
                    pair<int, int> current = que.front();
                    que.pop();

                    areas[current.first][current.second] = area;

                    for (size_t k = 0; k < 4; k++) {
                        int nxtY = current.first + dy[k];
                        int nxtX = current.second + dx[k];
                        if (nxtX < c && nxtX > -1 && nxtY < r && nxtY > -1 &&
                            !visited[nxtY][nxtX] && map[l][m] == map[nxtY][nxtX]) {
                            que.push(make_pair(nxtY, nxtX));
                            visited[nxtY][nxtX] = true;
                        }
                    }      
                }
                ++area;
            }
        }
    }




    cin >> n;
    while (n--) {
        int y1, x1, y2, x2;

        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, y2--, x2--;

        if(areas[y1][x1] == areas[y2][x2]){
            if(map[y1][x1] == '0') cout << "binary\n";
            else cout << "decimal\n";
        }else{
            cout << "neither\n";
        }
    }
    return 0;
}
