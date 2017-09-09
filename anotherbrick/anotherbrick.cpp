#include <iostream>

using namespace std;

int main(){
    int h, w, n, brick, level = 0;
    cin >> h >> w >> n;
    for(int i = 0; i < n; ++i){
        cin >> brick;
        level += brick;
        if(level > w){cout << "NO"; return 0;}
        if(level == w){level = 0;}
    }
    cout << "YES";
}
