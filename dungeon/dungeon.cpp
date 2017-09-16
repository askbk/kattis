#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct State{
    int moves, x, y, z;
    State(int _m, int _x, int _y, int _z){
        moves = _m;
        x = _x;
        y = _y;
        z = _z;
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int L, R, C, i, j, k, x, y, z, tx, ty, tz;
    bool visited[32][32][32], trapped;
    char map[32][32][32];
    const int dx[] = {0, 0, 1, 0, 0, -1};
    const int dy[] = {0, 1, 0, -1, 0, 0};
    const int dz[] = {1, 0, 0, 0, -1, 0};
    while(cin >> L >> R >> C){
        if(L == 0) return 0;
        queue<State> que;
        memset(visited, 0, sizeof visited);
        memset(map, '#', sizeof map);
        trapped = true;
        for(i = 1; i < L + 1; ++i){
            for(j = 1; j < R + 1; ++j){
                for(k = 1; k < C + 1; ++k){
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S'){
                        que.push(State(0, i, j, k));
                    }
                }
            }
        }

        while(!que.empty()){
            State current = que.front();
            que.pop();
            x = current.x; y = current.y; z = current.z;
            if(map[x][y][z] == 'E'){
                trapped = false;
                cout << "Escaped in " << current.moves << " minute(s).\n";
                break;
            }
            ++current.moves;
            for(i = 0; i < 6; ++i){
                tx = x + dx[i];
                ty = y + dy[i];
                tz = z + dz[i];
                if(map[tx][ty][tz] != '#' && !visited[tx][ty][tz]){
                    que.push(State(current.moves, tx, ty, tz));
                    visited[tx][ty][tz] = true;
                }
            }
        }
        if(trapped) cout << "Trapped!\n";
    }
}
