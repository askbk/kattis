#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << 0 << "\n";
        return 0;
    }
    bool prime[N+1];
    memset(prime, 1, sizeof prime);
    int ceiling = floor(sqrt(N))+1;
    for(int i = 2; i <= ceiling; i++){
        if(prime[i]){
            if(N % i == 0){
                cout << N - (N/i) << "\n";
                return 0;
            }
            for(int j = i*i; j*i <= N; ++j){
                prime[i*j] = false;
            }
        }
    }
    if(prime[N]) cout << N-1 << "\n";
}
