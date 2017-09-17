#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> pushed (10000000000, 0);
//bool pushed[1000000000000];

int main(){
    long long N, i, j, temp, counter;
    cin >> N;
    vector<long long> factors;
    vector<long long> friends;        
    long long ceiling = floor(sqrt(N));
    bool prime[ceiling];
    //memset(prime, 1, sizeof prime);

    for(i = 3; i <= ceiling; i += 2){
        prime[i] = true;
    }
    if(N % 2 == 0){
        friends.push_back(1);
        factors.push_back(2);
        pushed[1] = true;
        temp = N;
        counter = 1;
        while(temp % 2 == 0){
            temp /= 2;
            counter *= 2;
            if(!pushed[temp - 1]){
                friends.push_back(temp - 1); 
                pushed[temp - 1] = true;
            }
            if(!pushed[counter - 1]){
                friends.push_back(counter - 1);
                pushed[counter - 1] = true;
            }
        }
    }
    friends.push_back(0);
    pushed[0] = true;
    friends.push_back(N - 1);
    pushed[N - 1] = true;

    
    for(i = 3; i <= ceiling; i += 2){
        if(prime[i]){
            temp = N;
            if(temp % i == 0 && !pushed[i - 1]){
                factors.push_back(i);
                pushed[i - 1] = true;
                friends.push_back(i - 1);
                counter = 1;
                while(temp % i == 0){
                    temp /= i;
                    counter *= i;
                    if(!pushed[temp - 1]){
                        friends.push_back(temp - 1);
                        pushed[temp - 1] = true;
                    }
                    if(!pushed[counter - 1]){
                        friends.push_back(counter - 1);
                        pushed[counter - 1] = true;
                    }
                }
            }
            for(j = i; j * i <= ceiling; j += 2){
                prime[i * j] = false;
            }
        }
    }

    /*if(!pushed[ceiling - 1] && N % ceiling == 0){
        friends.push_back(ceiling - 1);
    }*/


    int fN = factors.size();
    long long mult;

    for(i = 0; i < fN; i += 2){
        for(j = i+1; j < fN; ++j){
            mult = factors[i] * factors[j];
            if(!pushed[mult] && N % mult == 0){
                pushed[mult] = true;
                counter = 1;
                temp = N;
                while(temp % mult == 0){
                    temp /= mult;
                    counter *= mult;
                    if(!pushed[temp - 1]){
                        friends.push_back(temp - 1);
                        pushed[temp] = true;
                    }
                    if(!pushed[counter - 1]){
                        friends.push_back(mult - 1);
                        pushed[counter - 1] = true;
                    }
                }
            }
        }
    }
    sort(friends.begin(), friends.end());
    long long sz = friends.size();

    for(i = 0; i < sz; ++i){
        cout << friends[i] << " ";
    }
}
