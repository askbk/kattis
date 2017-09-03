#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long divFak(const int a, const int b){
    int m = a, n = b;
    long long ans = 1;
    while(m > 1 || n > 1){
        if(m > 1){
            ans *= m;
            --m;
            ans *= m;
            --m;
        }
        if(n > 1){
            ans /= n;
            --n;
            ans /= n;
            --n;
        }
    }
    return ans;
}

int main(){
    int ceiling = 1000;
    bool prime[ceiling];
    vector<int> primeList;
    primeList.push_back(2);
    
    for(int i = 3; i <= ceiling; i += 2){
     	prime[i] = true;
    }
    
    cout << "prep done\n";
    for(int i = 3; i <= ceiling; i += 2){   //  finner primtall
      	if(prime[i]){
            primeList.push_back(i);
            if(primeList.size() == 63) break;
            for(int j = i; j * i <= ceiling; ++j){
                prime[i * j] = false;
            }
        }
    }
    cout << "primefinding finished\n";
    int primeN = 63;
    long long N;
    while(cin >> N){
        vector<int> powers;
        int currentP = 0;
        long long temp;

        for(int i = 0; i < primeN; ++i){    //  finner primfaktorene til N
            if(N % primeList[i] == 0){
                powers.push_back(1);
                temp = N / primeList[i];
                while(temp % primeList[i] == 0){    // finner antall av hver unike primfaktor
                    temp /= primeList[i];
                    ++powers[currentP];
                }
                ++currentP;
            }
        }

        temp = 1;
        int totalP = powers.size(), current = powers.size();
        for(int i = 0; i < totalP; ++i){    // tar fakultet av antall primfaktorer, delt på produktet av fakultetene til antall av hver unike primfaktor
            long long div = 1;
            while(powers[i] > 0){
                if(current >= 2){
                    temp *= current;
                    --current;
                    temp *= current;
                    --current;
                }
                div *= powers[i];
                --powers[i];
                div *= powers[i];
                --powers[i];
                temp /= div;
            }
        }
        cout << temp << "\n";
    }
}
