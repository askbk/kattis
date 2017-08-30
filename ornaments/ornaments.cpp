#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979

int main(){
    cout << fixed;
    cout << setprecision(2);
    for(;;){
        double r,h,s,v;
        cin >> r >> h >> s;
        if(r == 0 && h == 0 && s == 0) return 0;
        s = 1 + s / 100;
        v = acos(r / h);
        cout << 2 * s * (sqrt(h * h - r * r) + r * (PI - v)) << "\n";
    }
}
