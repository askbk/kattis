#include <iostream>
#include <set>

using namespace std;

int main(){
    char input;
    int i, j, count = 0;
    set<int> row, col, posDiag, negDiag;
    for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
            cin >> input;
            if(input == '*'){
                if(row.count(i) || col.count(j) || posDiag.count(i+j) || negDiag.count(i-j)){
                    cout << "invalid\n";
                    return 0;
                }
                ++count;
                row.insert(i); col.insert(j); posDiag.insert(i+j); negDiag.insert(i-j);
            } 
        }
    }
    if(count != 8){
        cout << "invalid\n";
    }else{
        cout << "valid\n";
    }
}
