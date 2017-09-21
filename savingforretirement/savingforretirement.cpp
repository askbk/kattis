#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int B, Br, Bs, A, As, ans;
    cin >> B >> Br >> Bs >> A >> As;
    ans = floor((Br*Bs - B*Bs + A*As)/As) + 1;
    cout << ans << "\n";
}
