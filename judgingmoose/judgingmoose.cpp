#include <iostream>

using namespace std;

int main(){
    int l, r;
    cin >> l >> r;
    if(l == 0 && r == 0){
        cout << "Not a moose\n";
        return 0;
    }

    if(l == r){
        cout << "Even " << 2 * r << "\n";
    } else if (l < r){
        cout << "Odd " << 2 * r << "\n";
    } else {
        cout << "Odd " << 2 * l << "\n";
    }
}
