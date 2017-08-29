#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

bool doubleEqual(double val1, double val2){
    return (abs(val1 - val2) < 0.00001);
}

int main(){
    int N;
    cin >> N;
    ++N;
    for(int i = 1; i < N; ++i){
        cout << "Case #" << i << ": ";
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double a, b, c, angles[3], semiP, area; // sides and angles
        a = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        b = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        semiP = (a + b + c) / 2;
        area = semiP * (semiP - a) * (semiP - b) * (semiP - c);
        if(area == 0){
            cout << "not a triangle\n";
            continue;
        }
        if(doubleEqual(a, b) || doubleEqual(a, c) || doubleEqual(b, c)){
            cout << "isosceles ";
        } else {
            cout << "scalene ";
        }
        
        angles[0] = acos((b * b + c * c - a * a) / (2 * b * c));
        angles[1] = acos((a * a + c * c - b * b) / (2 * a * c));
        angles[2] = acos((a * a + b * b - c * c) / (2 * b * a));
       
        bool fin = false;
        for(int j = 0; j < 3; ++j){
            if(doubleEqual(angles[j], PI / 2)){
                cout << "right triangle\n";
                fin = true;
                break;
            }else if(angles[j] > PI / 2) {
                cout << "obtuse triangle\n"; 
                fin = true;
                break;
            }
        }
        if(!fin){
            cout << "acute triangle\n"; 
            continue;
        }
    }
}
