#include <iostream>
#include <set>

using namespace std;

int main(){
    int N, in1, in2;
    set<int> x, y, posD, negD;
    cin >> N;
    while(N--){
        cin >> in1 >> in2;
        if(x.count(in1) || y.count(in2) || posD.count(in1-in2) || negD.count(in1+in2)){
            cout << "INCORRECT\n";
            return 0;
        }else{
            x.insert(in1); y.insert(in2); posD.insert(in1-in2); negD.insert(in1+in2);
        }
    }
    cout << "CORRECT\n";
}
