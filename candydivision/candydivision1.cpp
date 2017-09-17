#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> pushed (1000000000, 0);

int main(){
    long long N, i, j, temp, counter;
    cin >> N;
    vector<int> factors;
    vector<int> friends;        
    long long ceiling = floor(sqrt(N));
    bool prime[ceiling];
    //memset(prime, 1, sizeof prime);

    for(i = 3; i <= ceiling; i += 2){
        prime[i] = true;
    }
    if(N % 2 == 0){
        factors.push_back(1);
        pushed[1] = true;
    }
    friends.push_back(0);
    pushed[0] = true;
    friends.push_back(N - 1);
    pushed[N - 1] = true;

    
    for(i = 3; i <= ceiling; i += 2){
        if(prime[i]){
            temp = N;
            if(temp % i == 0 && !pushed[i - 1]){
                pushed[i - 1] = true;
                friends.push_back(i - 1);
            }
            for(j = i; j * i <= ceiling; j += 2){
                prime[i * j] = false;
            }
        }
    }
    if(!pushed[ceiling - 1] && N % ceiling == 0){
        friends.push_back(ceiling - 1);
    }
    sort(friends.begin(), friends.end());

    long long sz = fri::ends.size();

    for(i = 0; i < sz; ++i){
        cout << friends[i] << " ";
    }
}
