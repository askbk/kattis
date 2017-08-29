#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Spider{
    int height, moves, maxHeight;
    string path;
    Spider(int _h, int _m, int _mH, string _p){
        height = _h;
        moves = _m;
        maxHeight = _mH;
        path = _p;
    }
};

struct Route{
    int maxHeight;
    string path;
    Route(int _mH, string _p){
        maxHeight = _mH;
        path = _p;
    }
};

bool routeComp(Route i, Route j){
    return i.maxHeight > j.maxHeight;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        int M;
        cin >> M;
        int moves[M];
        int visitedMH[M][1000];
        memset(visitedMH, 10000, sizeof visitedMH);
        stack<Spider> stacc;
        vector<Route> routes;
        stacc.push(Spider(0, 0, 0, ""));

        for(int i = 0; i < M; ++i){
            cin >> moves[i];
        }

        while(!stacc.empty()){
            Spider current = stacc.top();
            stacc.pop();
            if(current.moves == M){
                if(current.height == 0){
                    routes.push_back(Route(current.maxHeight, current.path));
                }
                continue;
            }
            int newH, newM, newMH;
            newM = current.moves + 1;
            string newP;
            
            if(current.height >= moves[current.moves]){
                newMH = current.maxHeight;
                newH = current.height - moves[current.moves];
                if(visitedMH[current.moves+1][newH] > newMH){
                    newP = current.path;
                    newP.push_back('D');
                    stacc.push(Spider(newH, newM, current.maxHeight, newP));
                }
            }

            if(current.height + moves[current.moves] <= 1000){
                newH = current.height + moves[current.moves]; 
                if(newH > current.maxHeight){
                    newMH = newH;
                }

                if(visitedMH[current.moves+1][newH] > newMH){
                    newP = current.path;
                    newP.push_back('U');
                    visitedMH[current.moves+1][newH] = newMH;
                    stacc.push(Spider(newH, newM, current.maxHeight, newP));
                }
            }

                    }
        if(routes.size() == 0){
            cout << "IMPOSSIBLE\n";
        } else {
            sort(routes.begin(), routes.end(), routeComp);
            Route ans = routes[0];
            cout << ans.path << "\n";
        }
    }
}
