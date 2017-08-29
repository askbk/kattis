#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

int main(){
    for(;;){
        double r,h,s,v;
        cin >> r >> h >> s;
        if(r == 0 && h == 0 && s == 0) return 0;
        s = 1 + s / 100;
        v = acos(r / h);
        cout << 2 * (sqrt(h * h - r * r) + r * (PI - v)) * s << "\n";
    }
}
