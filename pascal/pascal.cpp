#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N == 1){
        cout << 0 << "\n";
        return 0;
    }
    if(N % 2 == 0){
        cout << N/2 << "\n";
        return 0;
    }


    int ceiling = floor(sqrt(N))+1;
    bool prime[N+1];
    //memset(prime, 1, sizeof prime);

    for(int i = 3; i <= ceiling; i += 2){
        prime[i] = true;
    }
    
    for(int i = 3; i <= ceiling; i += 2){
        if(prime[i]){
            if(N % i == 0){
                cout << N - (N/i) << "\n";
                return 0;
            }
            for(int j = i; j * i <= ceiling; ++j){
                prime[i * j] = false;
            }
        }
    }
    cout << N - 1 << "\n";
}
