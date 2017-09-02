#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    double maxT = pow(2, 63);
    long long max = maxT;
    long long ceiling = floor(sqrt(max))+1;
    bool prime[max];
    vector<int> primeList;
    primeList.push_back(2);
    //memset(prime, 1, sizeof prime);

    for(int i = 3; i <= max; i += 2){
     	prime[i] = true;
    }
    
    for(int i = 3; i <= ceiling; i += 2){   //  finner primtall
      	if(prime[i]){
            primeList.push_back(prime[i]);
            for(int j = i; j * i <= max; ++j){
                prime[i * j] = false;
            }
        }
    }

    int primeN = primeList.size(), N;
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
