#include <iostream>

using namespace std;

int main(){
    int N, counter = 1;
    cin >> N;
    while(N>1){
        if(N%2 == 1) ++N;
        N /= 2;
        ++counter;
    }
    cout << counter << "\n";
}
